// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <minfs/bcache.h>

#include <minfs/format.h>
#include <minfs/minfs.h>
#include <block-client/cpp/fake-device.h>
#include <fs/buffer/vmo_buffer.h>
#include <zxtest/zxtest.h>

namespace minfs {
namespace {

using block_client::BlockDevice;
using block_client::FakeBlockDevice;

constexpr uint32_t kBlockSize = 512;
constexpr uint32_t kNumBlocks = 20;

class MockBlockDevice : public FakeBlockDevice {
 public:
  MockBlockDevice() : FakeBlockDevice(kNumBlocks, kBlockSize) {}
  ~MockBlockDevice() {}

  void Reset() {
    called_ = false;
    request_ = {};
  }

  block_fifo_request_t request() const { return request_; }

  zx_status_t FifoTransaction(block_fifo_request_t* requests, size_t count) final {
    if (count != 1 || called_) {
      return ZX_ERR_IO_REFUSED;
    }
    called_ = true;
    request_ = *requests;
    return ZX_OK;
  }

 private:
  block_fifo_request_t request_ = {};
  bool called_ = false;
};


class BcacheTest : public zxtest::Test {
 public:
  void SetUp() final {
    auto device = std::make_unique<MockBlockDevice>();
    ASSERT_TRUE(device);
    device_ = device.get();

    ASSERT_OK(Bcache::Create(std::move(device), kNumBlocks, &bcache_));
  }

 protected:
  MockBlockDevice* device_ = nullptr;
  std::unique_ptr<Bcache> bcache_;
};

TEST_F(BcacheTest, GetDevice) {
  ASSERT_EQ(device_, bcache_->GetDevice());
}

TEST_F(BcacheTest, BlockNumberToDevice) {
  ASSERT_EQ(42 * kMinfsBlockSize / kBlockSize, bcache_->BlockNumberToDevice(42));
}

TEST_F(BcacheTest, RunOperation) {
  fs::VmoBuffer buffer;
  ASSERT_OK(buffer.Initialize(bcache_.get(), 1, kMinfsBlockSize, "source"));

  const uint64_t kVmoOffset = 1234;
  const uint64_t kDeviceOffset = 42;
  const uint64_t kLength = 5678;

  fs::Operation operation = {};
  operation.type = fs::OperationType::kWrite;
  operation.vmo_offset = kVmoOffset;
  operation.dev_offset = kDeviceOffset;
  operation.length = kLength;

  ASSERT_OK(bcache_->RunOperation(operation, &buffer));

  block_fifo_request_t request = device_->request();
  ASSERT_EQ(BLOCKIO_WRITE, request.opcode);
  ASSERT_EQ(buffer.vmoid(), request.vmoid);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kVmoOffset), request.vmo_offset);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kDeviceOffset), request.dev_offset);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kLength), request.length);

  operation.type = fs::OperationType::kRead;
  device_->Reset();

  ASSERT_OK(bcache_->RunOperation(operation, &buffer));

  request = device_->request();
  ASSERT_EQ(BLOCKIO_READ, request.opcode);
  ASSERT_EQ(buffer.vmoid(), request.vmoid);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kVmoOffset), request.vmo_offset);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kDeviceOffset), request.dev_offset);
  ASSERT_EQ(bcache_->BlockNumberToDevice(kLength), request.length);
}

}  // namespace
}  // namespace minfs
