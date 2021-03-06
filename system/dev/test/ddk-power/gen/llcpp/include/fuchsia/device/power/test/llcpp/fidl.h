// WARNING: This file is machine generated by fidlgen.

#pragma once

#include <lib/fidl/internal.h>
#include <lib/fidl/llcpp/array.h>
#include <lib/fidl/llcpp/coding.h>
#include <lib/fidl/llcpp/string_view.h>
#include <lib/fidl/llcpp/sync_call.h>
#include <lib/fidl/llcpp/traits.h>
#include <lib/fidl/llcpp/transaction.h>
#include <lib/fidl/llcpp/vector_view.h>
#include <lib/fit/function.h>
#include <lib/zx/channel.h>
#include <zircon/fidl.h>

#include <fuchsia/device/llcpp/fidl.h>

namespace llcpp {

namespace fuchsia {
namespace device {
namespace power {
namespace test {

struct TestDevice_GetCurrentDevicePowerState_Response;
struct TestDevice_GetCurrentDevicePowerState_Result;
struct TestDevice_AddDeviceWithPowerArgs_Response;
struct TestDevice_AddDeviceWithPowerArgs_Result;
class TestDevice;



struct TestDevice_GetCurrentDevicePowerState_Response {
  static constexpr const fidl_type_t* Type = nullptr;
  static constexpr uint32_t MaxNumHandles = 0;
  static constexpr uint32_t PrimarySize = 1;
  [[maybe_unused]]
  static constexpr uint32_t MaxOutOfLine = 0;

  ::llcpp::fuchsia::device::DevicePowerState cur_state = {};
};

extern "C" const fidl_type_t fuchsia_device_power_test_TestDevice_GetCurrentDevicePowerState_ResultTable;

struct TestDevice_GetCurrentDevicePowerState_Result {
  enum class Tag : fidl_union_tag_t {
    kResponse = 0,
    kErr = 1,
    Invalid = ::std::numeric_limits<::fidl_union_tag_t>::max(),
  };

  TestDevice_GetCurrentDevicePowerState_Result();
  ~TestDevice_GetCurrentDevicePowerState_Result();

  TestDevice_GetCurrentDevicePowerState_Result(TestDevice_GetCurrentDevicePowerState_Result&& other) {
    tag_ = Tag::Invalid;
    if (this != &other) {
      MoveImpl_(std::move(other));
    }
  }

  TestDevice_GetCurrentDevicePowerState_Result& operator=(TestDevice_GetCurrentDevicePowerState_Result&& other) {
    if (this != &other) {
      MoveImpl_(std::move(other));
    }
    return *this;
  }

  bool has_invalid_tag() const { return tag_ == Tag::Invalid; }

  bool is_response() const { return tag_ == Tag::kResponse; }

  TestDevice_GetCurrentDevicePowerState_Response& mutable_response();

  template <typename T>
  std::enable_if_t<std::is_convertible<T, TestDevice_GetCurrentDevicePowerState_Response>::value && std::is_copy_assignable<T>::value>
  set_response(const T& v) {
    mutable_response() = v;
  }

  template <typename T>
  std::enable_if_t<std::is_convertible<T, TestDevice_GetCurrentDevicePowerState_Response>::value && std::is_move_assignable<T>::value>
  set_response(T&& v) {
    mutable_response() = std::move(v);
  }

  TestDevice_GetCurrentDevicePowerState_Response const & response() const { return response_; }

  bool is_err() const { return tag_ == Tag::kErr; }

  int32_t& mutable_err();

  template <typename T>
  std::enable_if_t<std::is_convertible<T, int32_t>::value && std::is_copy_assignable<T>::value>
  set_err(const T& v) {
    mutable_err() = v;
  }

  template <typename T>
  std::enable_if_t<std::is_convertible<T, int32_t>::value && std::is_move_assignable<T>::value>
  set_err(T&& v) {
    mutable_err() = std::move(v);
  }

  int32_t const & err() const { return err_; }

  Tag which() const { return tag_; }

  static constexpr const fidl_type_t* Type = &fuchsia_device_power_test_TestDevice_GetCurrentDevicePowerState_ResultTable;
  static constexpr uint32_t MaxNumHandles = 0;
  static constexpr uint32_t PrimarySize = 8;
  [[maybe_unused]]
  static constexpr uint32_t MaxOutOfLine = 0;

 private:
  void Destroy();
  void MoveImpl_(TestDevice_GetCurrentDevicePowerState_Result&& other);
  static void SizeAndOffsetAssertionHelper();
  Tag tag_;
  union {
    TestDevice_GetCurrentDevicePowerState_Response response_;
    int32_t err_;
  };
};



struct TestDevice_AddDeviceWithPowerArgs_Response {
  static constexpr const fidl_type_t* Type = nullptr;
  static constexpr uint32_t MaxNumHandles = 0;
  static constexpr uint32_t PrimarySize = 1;
  [[maybe_unused]]
  static constexpr uint32_t MaxOutOfLine = 0;

  uint8_t __reserved = {};
};

extern "C" const fidl_type_t fuchsia_device_power_test_TestDevice_AddDeviceWithPowerArgs_ResultTable;

struct TestDevice_AddDeviceWithPowerArgs_Result {
  enum class Tag : fidl_union_tag_t {
    kResponse = 0,
    kErr = 1,
    Invalid = ::std::numeric_limits<::fidl_union_tag_t>::max(),
  };

  TestDevice_AddDeviceWithPowerArgs_Result();
  ~TestDevice_AddDeviceWithPowerArgs_Result();

  TestDevice_AddDeviceWithPowerArgs_Result(TestDevice_AddDeviceWithPowerArgs_Result&& other) {
    tag_ = Tag::Invalid;
    if (this != &other) {
      MoveImpl_(std::move(other));
    }
  }

  TestDevice_AddDeviceWithPowerArgs_Result& operator=(TestDevice_AddDeviceWithPowerArgs_Result&& other) {
    if (this != &other) {
      MoveImpl_(std::move(other));
    }
    return *this;
  }

  bool has_invalid_tag() const { return tag_ == Tag::Invalid; }

  bool is_response() const { return tag_ == Tag::kResponse; }

  TestDevice_AddDeviceWithPowerArgs_Response& mutable_response();

  template <typename T>
  std::enable_if_t<std::is_convertible<T, TestDevice_AddDeviceWithPowerArgs_Response>::value && std::is_copy_assignable<T>::value>
  set_response(const T& v) {
    mutable_response() = v;
  }

  template <typename T>
  std::enable_if_t<std::is_convertible<T, TestDevice_AddDeviceWithPowerArgs_Response>::value && std::is_move_assignable<T>::value>
  set_response(T&& v) {
    mutable_response() = std::move(v);
  }

  TestDevice_AddDeviceWithPowerArgs_Response const & response() const { return response_; }

  bool is_err() const { return tag_ == Tag::kErr; }

  int32_t& mutable_err();

  template <typename T>
  std::enable_if_t<std::is_convertible<T, int32_t>::value && std::is_copy_assignable<T>::value>
  set_err(const T& v) {
    mutable_err() = v;
  }

  template <typename T>
  std::enable_if_t<std::is_convertible<T, int32_t>::value && std::is_move_assignable<T>::value>
  set_err(T&& v) {
    mutable_err() = std::move(v);
  }

  int32_t const & err() const { return err_; }

  Tag which() const { return tag_; }

  static constexpr const fidl_type_t* Type = &fuchsia_device_power_test_TestDevice_AddDeviceWithPowerArgs_ResultTable;
  static constexpr uint32_t MaxNumHandles = 0;
  static constexpr uint32_t PrimarySize = 8;
  [[maybe_unused]]
  static constexpr uint32_t MaxOutOfLine = 0;

 private:
  void Destroy();
  void MoveImpl_(TestDevice_AddDeviceWithPowerArgs_Result&& other);
  static void SizeAndOffsetAssertionHelper();
  Tag tag_;
  union {
    TestDevice_AddDeviceWithPowerArgs_Response response_;
    int32_t err_;
  };
};

extern "C" const fidl_type_t fuchsia_device_power_test_TestDeviceAddDeviceWithPowerArgsRequestTable;
extern "C" const fidl_type_t fuchsia_device_power_test_TestDeviceAddDeviceWithPowerArgsResponseTable;
extern "C" const fidl_type_t fuchsia_device_power_test_TestDeviceGetCurrentDevicePowerStateResponseTable;

class TestDevice final {
  TestDevice() = delete;
 public:

  struct AddDeviceWithPowerArgsResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    TestDevice_AddDeviceWithPowerArgs_Result result;

    static constexpr const fidl_type_t* Type = &fuchsia_device_power_test_TestDeviceAddDeviceWithPowerArgsResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kResponse;
  };
  struct AddDeviceWithPowerArgsRequest final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info;

    static constexpr const fidl_type_t* Type = &fuchsia_device_power_test_TestDeviceAddDeviceWithPowerArgsRequestTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 32;
    static constexpr uint32_t MaxOutOfLine = 4294967295;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kRequest;
    using ResponseType = AddDeviceWithPowerArgsResponse;
  };

  struct GetCurrentDevicePowerStateResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    TestDevice_GetCurrentDevicePowerState_Result result;

    static constexpr const fidl_type_t* Type = &fuchsia_device_power_test_TestDeviceGetCurrentDevicePowerStateResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    static constexpr bool HasFlexibleEnvelope = false;
    static constexpr ::fidl::internal::TransactionalMessageKind MessageKind =
        ::fidl::internal::TransactionalMessageKind::kResponse;
  };
  using GetCurrentDevicePowerStateRequest = ::fidl::AnyZeroArgMessage;


  // Collection of return types of FIDL calls in this interface.
  class ResultOf final {
    ResultOf() = delete;
   private:
    template <typename ResponseType>
    class AddDeviceWithPowerArgs_Impl final : private ::fidl::internal::OwnedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::OwnedSyncCallBase<ResponseType>;
     public:
      AddDeviceWithPowerArgs_Impl(zx::unowned_channel _client_end, ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info);
      ~AddDeviceWithPowerArgs_Impl() = default;
      AddDeviceWithPowerArgs_Impl(AddDeviceWithPowerArgs_Impl&& other) = default;
      AddDeviceWithPowerArgs_Impl& operator=(AddDeviceWithPowerArgs_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class GetCurrentDevicePowerState_Impl final : private ::fidl::internal::OwnedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::OwnedSyncCallBase<ResponseType>;
     public:
      GetCurrentDevicePowerState_Impl(zx::unowned_channel _client_end);
      ~GetCurrentDevicePowerState_Impl() = default;
      GetCurrentDevicePowerState_Impl(GetCurrentDevicePowerState_Impl&& other) = default;
      GetCurrentDevicePowerState_Impl& operator=(GetCurrentDevicePowerState_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };

   public:
    using AddDeviceWithPowerArgs = AddDeviceWithPowerArgs_Impl<AddDeviceWithPowerArgsResponse>;
    using GetCurrentDevicePowerState = GetCurrentDevicePowerState_Impl<GetCurrentDevicePowerStateResponse>;
  };

  // Collection of return types of FIDL calls in this interface,
  // when the caller-allocate flavor or in-place call is used.
  class UnownedResultOf final {
    UnownedResultOf() = delete;
   private:
    template <typename ResponseType>
    class AddDeviceWithPowerArgs_Impl final : private ::fidl::internal::UnownedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::UnownedSyncCallBase<ResponseType>;
     public:
      AddDeviceWithPowerArgs_Impl(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info, ::fidl::BytePart _response_buffer);
      ~AddDeviceWithPowerArgs_Impl() = default;
      AddDeviceWithPowerArgs_Impl(AddDeviceWithPowerArgs_Impl&& other) = default;
      AddDeviceWithPowerArgs_Impl& operator=(AddDeviceWithPowerArgs_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };
    template <typename ResponseType>
    class GetCurrentDevicePowerState_Impl final : private ::fidl::internal::UnownedSyncCallBase<ResponseType> {
      using Super = ::fidl::internal::UnownedSyncCallBase<ResponseType>;
     public:
      GetCurrentDevicePowerState_Impl(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);
      ~GetCurrentDevicePowerState_Impl() = default;
      GetCurrentDevicePowerState_Impl(GetCurrentDevicePowerState_Impl&& other) = default;
      GetCurrentDevicePowerState_Impl& operator=(GetCurrentDevicePowerState_Impl&& other) = default;
      using Super::status;
      using Super::error;
      using Super::ok;
      using Super::Unwrap;
      using Super::value;
      using Super::operator->;
      using Super::operator*;
    };

   public:
    using AddDeviceWithPowerArgs = AddDeviceWithPowerArgs_Impl<AddDeviceWithPowerArgsResponse>;
    using GetCurrentDevicePowerState = GetCurrentDevicePowerState_Impl<GetCurrentDevicePowerStateResponse>;
  };

  class SyncClient final {
   public:
    explicit SyncClient(::zx::channel channel) : channel_(std::move(channel)) {}
    ~SyncClient() = default;
    SyncClient(SyncClient&&) = default;
    SyncClient& operator=(SyncClient&&) = default;

    const ::zx::channel& channel() const { return channel_; }

    ::zx::channel* mutable_channel() { return &channel_; }

    // Add Test Device with some powerargs
    // Allocates 24 bytes of response buffer on the stack. Request is heap-allocated.
    ResultOf::AddDeviceWithPowerArgs AddDeviceWithPowerArgs(::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info);

    // Add Test Device with some powerargs
    // Caller provides the backing storage for FIDL message via request and response buffers.
    UnownedResultOf::AddDeviceWithPowerArgs AddDeviceWithPowerArgs(::fidl::BytePart _request_buffer, ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info, ::fidl::BytePart _response_buffer);

    // Get current power state of the device
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    ResultOf::GetCurrentDevicePowerState GetCurrentDevicePowerState();

    // Get current power state of the device
    // Caller provides the backing storage for FIDL message via request and response buffers.
    UnownedResultOf::GetCurrentDevicePowerState GetCurrentDevicePowerState(::fidl::BytePart _response_buffer);

   private:
    ::zx::channel channel_;
  };

  // Methods to make a sync FIDL call directly on an unowned channel, avoiding setting up a client.
  class Call final {
    Call() = delete;
   public:

    // Add Test Device with some powerargs
    // Allocates 24 bytes of response buffer on the stack. Request is heap-allocated.
    static ResultOf::AddDeviceWithPowerArgs AddDeviceWithPowerArgs(zx::unowned_channel _client_end, ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info);

    // Add Test Device with some powerargs
    // Caller provides the backing storage for FIDL message via request and response buffers.
    static UnownedResultOf::AddDeviceWithPowerArgs AddDeviceWithPowerArgs(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, ::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info, ::fidl::BytePart _response_buffer);

    // Get current power state of the device
    // Allocates 40 bytes of message buffer on the stack. No heap allocation necessary.
    static ResultOf::GetCurrentDevicePowerState GetCurrentDevicePowerState(zx::unowned_channel _client_end);

    // Get current power state of the device
    // Caller provides the backing storage for FIDL message via request and response buffers.
    static UnownedResultOf::GetCurrentDevicePowerState GetCurrentDevicePowerState(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer);

  };

  // Messages are encoded and decoded in-place when these methods are used.
  // Additionally, requests must be already laid-out according to the FIDL wire-format.
  class InPlace final {
    InPlace() = delete;
   public:

    // Add Test Device with some powerargs
    static ::fidl::DecodeResult<AddDeviceWithPowerArgsResponse> AddDeviceWithPowerArgs(zx::unowned_channel _client_end, ::fidl::DecodedMessage<AddDeviceWithPowerArgsRequest> params, ::fidl::BytePart response_buffer);

    // Get current power state of the device
    static ::fidl::DecodeResult<GetCurrentDevicePowerStateResponse> GetCurrentDevicePowerState(zx::unowned_channel _client_end, ::fidl::BytePart response_buffer);

  };

  // Pure-virtual interface to be implemented by a server.
  class Interface {
   public:
    Interface() = default;
    virtual ~Interface() = default;
    using _Outer = TestDevice;
    using _Base = ::fidl::CompleterBase;

    class AddDeviceWithPowerArgsCompleterBase : public _Base {
     public:
      void Reply(TestDevice_AddDeviceWithPowerArgs_Result result);
      void Reply(::fidl::BytePart _buffer, TestDevice_AddDeviceWithPowerArgs_Result result);
      void Reply(::fidl::DecodedMessage<AddDeviceWithPowerArgsResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using AddDeviceWithPowerArgsCompleter = ::fidl::Completer<AddDeviceWithPowerArgsCompleterBase>;

    virtual void AddDeviceWithPowerArgs(::fidl::VectorView<::llcpp::fuchsia::device::DevicePowerStateInfo> info, AddDeviceWithPowerArgsCompleter::Sync _completer) = 0;

    class GetCurrentDevicePowerStateCompleterBase : public _Base {
     public:
      void Reply(TestDevice_GetCurrentDevicePowerState_Result result);
      void Reply(::fidl::BytePart _buffer, TestDevice_GetCurrentDevicePowerState_Result result);
      void Reply(::fidl::DecodedMessage<GetCurrentDevicePowerStateResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using GetCurrentDevicePowerStateCompleter = ::fidl::Completer<GetCurrentDevicePowerStateCompleterBase>;

    virtual void GetCurrentDevicePowerState(GetCurrentDevicePowerStateCompleter::Sync _completer) = 0;

  };

  // Attempts to dispatch the incoming message to a handler function in the server implementation.
  // If there is no matching handler, it returns false, leaving the message and transaction intact.
  // In all other cases, it consumes the message and returns true.
  // It is possible to chain multiple TryDispatch functions in this manner.
  static bool TryDispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Dispatches the incoming message to one of the handlers functions in the interface.
  // If there is no matching handler, it closes all the handles in |msg| and closes the channel with
  // a |ZX_ERR_NOT_SUPPORTED| epitaph, before returning false. The message should then be discarded.
  static bool Dispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Same as |Dispatch|, but takes a |void*| instead of |Interface*|. Only used with |fidl::Bind|
  // to reduce template expansion.
  // Do not call this method manually. Use |Dispatch| instead.
  static bool TypeErasedDispatch(void* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
    return Dispatch(static_cast<Interface*>(impl), msg, txn);
  }

};

}  // namespace test
}  // namespace power
}  // namespace device
}  // namespace fuchsia
}  // namespace llcpp

namespace fidl {

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Response> : public std::true_type {};
static_assert(std::is_standard_layout_v<::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Response>);
static_assert(offsetof(::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Response, cur_state) == 0);
static_assert(sizeof(::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Response) == ::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Response::PrimarySize);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Result> : public std::true_type {};
static_assert(std::is_standard_layout_v<::llcpp::fuchsia::device::power::test::TestDevice_GetCurrentDevicePowerState_Result>);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Response> : public std::true_type {};
static_assert(std::is_standard_layout_v<::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Response>);
static_assert(offsetof(::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Response, __reserved) == 0);
static_assert(sizeof(::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Response) == ::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Response::PrimarySize);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Result> : public std::true_type {};
static_assert(std::is_standard_layout_v<::llcpp::fuchsia::device::power::test::TestDevice_AddDeviceWithPowerArgs_Result>);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsRequest> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsRequest> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsRequest)
    == ::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsRequest::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsRequest, info) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsResponse)
    == ::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::device::power::test::TestDevice::AddDeviceWithPowerArgsResponse, result) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::device::power::test::TestDevice::GetCurrentDevicePowerStateResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::device::power::test::TestDevice::GetCurrentDevicePowerStateResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::device::power::test::TestDevice::GetCurrentDevicePowerStateResponse)
    == ::llcpp::fuchsia::device::power::test::TestDevice::GetCurrentDevicePowerStateResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::device::power::test::TestDevice::GetCurrentDevicePowerStateResponse, result) == 16);

}  // namespace fidl
