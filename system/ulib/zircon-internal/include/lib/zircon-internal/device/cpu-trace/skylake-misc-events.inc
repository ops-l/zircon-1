// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Database of miscellaneous Intel-specific performance monitor registers.
// This has the benefit of providing the data in a usage-independent way.
// See, e.g., desktop-6th-gen-core-family-datasheet-vol-2.

#ifndef DEF_MISC_SKL_EVENT
#error DEF_MISC_SKL_EVENT not defined
#endif

// Miscellaneous performance counters for Skylake
// args:
// - symbol (used in code, must be unique for all symbols within an arch)
//   (must be VALID_C_SYMBOL)
// - event name (used in trace specification files)
//   (must be valid_c_symbol, without the group prefix,
//   i.e., instructions_retired not fixed_instructions_retired)
// - id (10 bits, must be unique for each DEF_MISC_SKL_EVENT entry)
// - offset (the offset from BAR of the value)
// - size (in bits, either 32 or 64)
// - flags (IPM_MISC_REG_FLAG_* values) (uint32_t) [at present there are none]
// - readable name (ideally max 24 chars for legibility in display in chrome)
// - description (if empty use "")
//
// These counters are kinda like fixed counters except there's no need to
// specify a h/w register number: there isn't any.
// Misc counter id rule: |id| must be <= PERFMON_MAX_EVENT. 
//
// All current misc counters require a timebase, so that is the default
// for misc regs. This affects configuration: If one of these is requested
// in sampling mode and there is no timebase, then configuration fails.

DEF_MISC_SKL_EVENT(MISC_MEM_BYTES_READ,
  memory_bytes_read,
  0, 0x5050, 32, 0,
  "Memory Bytes Read",    "64 byte lines read, from controller, recorded as bytes")
DEF_MISC_SKL_EVENT(MISC_MEM_BYTES_WRITTEN,
  memory_bytes_written,
  1, 0x5054, 32, 0,
  "Memory Bytes Written", "64 byte lines written, from controller, recorded as bytes")

DEF_MISC_SKL_EVENT(MISC_MEM_GT_REQUESTS,
  memory_gt_requests,
  2, 0x5040, 32, 0,
  "Memory requests from GT",
  "64 byte line requests to controller from GT, including partial requests that are later combined")
DEF_MISC_SKL_EVENT(MISC_MEM_IA_REQUESTS,
  memory_ia_requests,
  3, 0x5044, 32, 0,
  "Memory requests from IA",
  "64 byte line requests to controller from IA, including partial requests that are later combined")
DEF_MISC_SKL_EVENT(MISC_MEM_IO_REQUESTS,
  memory_io_requests,
  4, 0x5048, 32, 0,
  "Memory requests from IO",
  "64 byte line requests to controller from IO, including partial requests that are later combined")

DEF_MISC_SKL_EVENT(MISC_PKG_ALL_ACTIVE_CORE_CYCLES,
  all_active_core_cycles,
  10, 0x5828, 64, 0,
  "All active core cycles",
  "Sum of all active core cycles (in C0 state), rate is same as TSC")
DEF_MISC_SKL_EVENT(MISC_PKG_ANY_ACTIVE_CORE_CYCLES,
  any_active_core_cycles,
  11, 0x5830, 64, 0,
  "Any active core cycles ",
  "Sum of any active core cycles (in C0 state), rate is same as TSC")
DEF_MISC_SKL_EVENT(MISC_PKG_ACTIVE_GT_CYCLES,
  active_gt_cycles,
  12, 0x5838, 64, 0,
  "Active GT cycles",
  "Sum of active GT cycles (in C0 state), rate is same as TSC")
DEF_MISC_SKL_EVENT(MISC_PKG_ACTIVE_IA_GT_CYCLES,
  active_ia_gt_cycles,
  13, 0x5840, 64, 0,
  "Active IA/GT cycles",
  "Sum of cycles when GT and IA are both active (in C0 state), rate is same as TSC")
DEF_MISC_SKL_EVENT(MISC_PKG_ACTIVE_GT_SLICE_CYCLES,
  active_gt_slice_cycles,
  14, 0x5848, 64, 0,
  "Active GT slice cycles",
  "Sum of active GT slice cycles, rate is 24Mhz")
DEF_MISC_SKL_EVENT(MISC_PKG_ACTIVE_GT_ENGINE_CYCLES,
  active_gt_engine_cycles,
  15, 0x5858, 64, 0,
  "Active GT engine cycles",
  "Sum of active GT engine cycles, rate is 24Mhz")

// TODO(dje): Display this better.
DEF_MISC_SKL_EVENT(MISC_PKG_PECI_THERM_MARGIN,
  peci_thermal_margin,
  20, 0x58a8, 32, IPM_MISC_REG_FLAG_RAW,
  "PECI thermal margin",
  "")

DEF_MISC_SKL_EVENT(MISC_PKG_RAPL_PERF_STATUS,
  rapl_performance_status,
  21, 0x58f0, 32, 0,
  "RAPL performance status",
  "Count of the time units when RAPL was limiting P-states (within 1/1024 second window)")

// TODO(dje): This one value is actually a collection of several values.
// Not sure how to display it (could split it into individual pieces but
// that's a lot).
DEF_MISC_SKL_EVENT(MISC_PKG_IA_FREQ_CLAMPING_REASONS,
  ia_frequency_clamping,
  22, 0x58fc, 32, IPM_MISC_REG_FLAG_FIELDS,
  "IA frequency clamping",
  "Reasons for IA frequency to be clamped below the requested frequency")
DEF_MISC_SKL_EVENT(MISC_PKG_GT_FREQ_CLAMPING_REASONS,
  gt_frequency_clamping,
  23, 0x5900, 32, IPM_MISC_REG_FLAG_FIELDS,
  "GT frequency clamping",
  "Reasons for GT frequency to be clamped below the requested frequency")

// These values all come from the same register.
// It is up to code to pull out the relevant value.
DEF_MISC_SKL_EVENT(MISC_PKG_RP_GT_SLICE_FREQ,
  fp_gt_slice_freq,
  24, 0x5948, 32, 0,
  "RP GT slice freq",
  "GT Slice frequency (granularity of 16.666Mhz)")
DEF_MISC_SKL_EVENT(MISC_PKG_RP_GT_UNSLICE_FREQ,
  rp_gt_unslice_freq,
  25, 0x5948, 32, 0,
  "RP GT unslice freq",
  "GT Unslice frequency (granularity of 16.666Mhz)")
DEF_MISC_SKL_EVENT(MISC_PKG_RP_GT_VOLT,
  rp_gt_voltage,
  26, 0x5948, 32, 0,
  "RP GT voltage",
  "Voltage of the current RP-state")

DEF_MISC_SKL_EVENT(MISC_PKG_EDRAM_TEMP,
  edram_temperature,
  27, 0x594c, 32, 0,
  "EDRAM temperature",
  "")
DEF_MISC_SKL_EVENT(MISC_PKG_PKG_TEMP,
  package_temperature,
  28, 0x5978, 32, 0,
  "Package temperature",
  "")
DEF_MISC_SKL_EVENT(MISC_PKG_IA_TEMP,
  ia_temperature,
  29, 0x597c, 32, 0,
  "IA temperature",
  "")
DEF_MISC_SKL_EVENT(MISC_PKG_GT_TEMP,
  gt_temperature,
  30, 0x5980, 32, 0,
  "GT temperature",
  "")

#undef DEF_MISC_SKL_EVENT
