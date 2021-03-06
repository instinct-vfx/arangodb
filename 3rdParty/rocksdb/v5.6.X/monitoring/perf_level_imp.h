//  Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//  This source code is also licensed under the GPLv2 license found in the
//  COPYING file in the root directory of this source tree.
//
#pragma once
#include "rocksdb/perf_level.h"
#include "port/port.h"

namespace rocksdb {

#ifdef ROCKSDB_SUPPORT_THREAD_LOCAL
extern __thread PerfLevel perf_level;
#else
extern PerfLevel perf_level;
#endif

}  // namespace rocksdb
