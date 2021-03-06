/*
// Copyright (c) 2015 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/
#include "sat-rtit-overflow-heuristics.h"
#include <cstdio>
#include <cinttypes>

using namespace sat;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rtit-trace-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    overflow_map overflows;
    if (!time_overflows(argv[1], true, overflows)) {
        fprintf(stderr, "estimating timestamps for overflows failed\n");
        //exit(EXIT_FAILURE);
    }

    printf("%" PRIu64 " overflows\n", (uint64_t)overflows.size());
    for (auto& o : overflows) {
        printf("%08" PRIx64 ": OVERFLOW %" PRIx64 " +- %" PRIx64 "\n",
               o.first, o.second.first, o.second.second);
    }
}
