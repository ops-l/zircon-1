# Copyright 2018 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := banjo

MODULE_PACKAGE := banjo

MODULE_BANJO_LIBRARY := ddk.protocol.ethernet

MODULE_BANJO_NAME := ethernet

MODULE_BANJO_DEPS := system/banjo/zircon-listnode

MODULE_SRCS += $(LOCAL_DIR)/ethernet.banjo

include make/module.mk
