////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2017 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Simon Grätzer
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGOD_ROCKSDB_ROCKSDB_INCREMENTAL_SYNC_H
#define ARANGOD_ROCKSDB_ROCKSDB_INCREMENTAL_SYNC_H 1

#include "Basics/Common.h"
#include "Replication/InitialSyncer.h"
#include "VocBase/LogicalCollection.h"

namespace arangodb {
class LogicalCollection;

int syncChunkRocksDB(
    InitialSyncer& syncer, SingleCollectionTransaction* trx,
    std::string const& keysId, uint64_t chunkId, std::string const& lowString,
    std::string const& highString,
    std::vector<std::pair<std::string, uint64_t>> const& markers,
    std::string& errorMsg);

int handleSyncKeysRocksDB(InitialSyncer& syncer,
                          arangodb::LogicalCollection* col,
                          std::string const& keysId, std::string const& cid,
                          std::string const& collectionName,
                          TRI_voc_tick_t maxTick, std::string& errorMsg);
}

#endif
