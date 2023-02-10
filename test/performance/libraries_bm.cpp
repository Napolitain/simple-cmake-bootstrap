//
// Created by Maxime Boucher on 14/01/2023.
//

#include "../../lib/inc/statistics.hpp"
#include "benchmark/benchmark.h"
#include "folly/FBVector.h"
#include "absl/container/flat_hash_map.h"
#include "folly/container/F14Map.h"
#include <unordered_map>
#include "absl/container/inlined_vector.h"

static void BM_stdVectorSmall(benchmark::State &state) {
    // Perform setup here
    std::vector<int> data = {1, 2, 3, 4, 5};
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_fbVectorSmall(benchmark::State &state) {
    // Perform setup here
    folly::fbvector<int> data = {1, 2, 3, 4, 5};
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_inlinedVectorSmall(benchmark::State &state) {
    // Perform setup here
    absl::InlinedVector<int, 5> data = {1, 2, 3, 4, 5};
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_stdVectorLarge(benchmark::State &state) {
    // Perform setup here
    std::vector<int> data;
    for (int i = 0; i < 1000000; i++) {
        data.push_back(i);
    }
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_inlinedVectorLarge(benchmark::State &state) {
    // Perform setup here
    absl::InlinedVector<int, 1000000> data;
    for (int i = 0; i < 1000000; i++) {
        data.push_back(i);
    }
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_fbVectorLarge(benchmark::State &state) {
    // Perform setup here
    folly::fbvector<int> data;
    for (int i = 0; i < 1000000; i++) {
        data.push_back(i);
    }
    for (auto _: state) {
        // This code gets timed
        statistics::mean(data);
    }
}

static void BM_stdVectorPushBack(benchmark::State &state) {
    // Perform setup here
    std::vector<int> data;
    for (auto _: state) {
        // This code gets timed
        data.push_back(1);
    }
}

static void BM_fbVectorPushBack(benchmark::State &state) {
    // Perform setup here
    folly::fbvector<int> data;
    for (auto _: state) {
        // This code gets timed
        data.push_back(1);
    }
}

/**
 * Benchmark a small, std::unordered_map, folly::F14FastMap, and absl::flat_hash_map
 * Test the index operator speed
 */
static void BM_stdUnorderedMapSmall(benchmark::State &state) {
    // Perform setup here
    std::unordered_map<int, int> data;
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_f14FastMapSmall(benchmark::State &state) {
    // Perform setup here
    folly::F14FastMap<int, int> data;
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_flatHashMapSmall(benchmark::State &state) {
    // Perform setup here
    absl::flat_hash_map<int, int> data;
    for (int i = 0; i < 100; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

/**
 * Benchmark a large, std::unordered_map, folly::F14FastMap, and absl::flat_hash_map
 * Test the index operator speed
 */
static void BM_stdUnorderedMapLarge(benchmark::State &state) {
    // Perform setup here
    std::unordered_map<int, int> data;
    for (int i = 0; i < 1000000; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_f14FastMapLarge(benchmark::State &state) {
    // Perform setup here
    folly::F14FastMap<int, int> data;
    for (int i = 0; i < 1000000; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_flatHashMapLarge(benchmark::State &state) {
    // Perform setup here
    absl::flat_hash_map<int, int> data;
    for (int i = 0; i < 1000000; i++) {
        data[i] = i;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

/**
 * Benchmark a small, std::unordered_map, folly::F14FastMap, and absl::flat_hash_map
 * Test the insert speed
 */
static void BM_stdUnorderedMapInsertSmall(benchmark::State &state) {
    // Perform setup here
    std::unordered_map<int, int> data;
    for (auto _: state) {
        // This code gets timed
        data[1] = 1;
    }
}

static void BM_f14FastMapInsertSmall(benchmark::State &state) {
    // Perform setup here
    folly::F14FastMap<int, int> data;
    for (auto _: state) {
        // This code gets timed
        data[1] = 1;
    }
}

static void BM_flatHashMapInsertSmall(benchmark::State &state) {
    // Perform setup here
    absl::flat_hash_map<int, int> data;
    for (auto _: state) {
        // This code gets timed
        data[1] = 1;
    }
}

/**
 * Benchmarka hashmap of vector size 1000, std::unordered_map, folly::F14FastMap, and absl::flat_hash_map
 * Test the index operator speed
 */
static void BM_stdUnorderedMapVectorSmall(benchmark::State &state) {
    // Perform setup here
    std::unordered_map<int, std::vector<int>> data;
    std::vector<int> vec(1000);
    for (int i = 0; i < 100; i++) {
        data[i] = vec;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_f14FastMapVectorSmall(benchmark::State &state) {
    // Perform setup here
    folly::F14FastMap<int, std::vector<int>> data;
    std::vector<int> vec(1000);
    for (int i = 0; i < 100; i++) {
        data[i] = vec;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

static void BM_flatHashMapVectorSmall(benchmark::State &state) {
    // Perform setup here
    absl::flat_hash_map<int, std::vector<int>> data;
    std::vector<int> vec(1000);
    for (int i = 0; i < 100; i++) {
        data[i] = vec;
    }
    for (auto _: state) {
        // This code gets timed
        data[1];
    }
}

// vectors
BENCHMARK(BM_stdVectorSmall);
BENCHMARK(BM_fbVectorSmall);
BENCHMARK(BM_inlinedVectorSmall);
BENCHMARK(BM_stdVectorLarge);
BENCHMARK(BM_inlinedVectorLarge);
BENCHMARK(BM_fbVectorLarge);

// push_back
BENCHMARK(BM_stdVectorPushBack);
BENCHMARK(BM_fbVectorPushBack);

// maps
BENCHMARK(BM_stdUnorderedMapSmall);
BENCHMARK(BM_f14FastMapSmall);
BENCHMARK(BM_flatHashMapSmall);
BENCHMARK(BM_stdUnorderedMapLarge);
BENCHMARK(BM_f14FastMapLarge);
BENCHMARK(BM_flatHashMapLarge);

// maps insert
BENCHMARK(BM_stdUnorderedMapInsertSmall);
BENCHMARK(BM_f14FastMapInsertSmall);
BENCHMARK(BM_flatHashMapInsertSmall);

// maps of vectors
BENCHMARK(BM_stdUnorderedMapVectorSmall);
BENCHMARK(BM_f14FastMapVectorSmall);
BENCHMARK(BM_flatHashMapVectorSmall);

static void BM_statisticsVectorBubbleSort(benchmark::State &state) {
    // Perform setup here
    statistics::vector<int> data(1000);
    for (auto _: state) {
        // This code gets timed
        data.bubbleSort();
    }
}

static void BM_statisticsVectorQuickSort(benchmark::State &state) {
    // Perform setup here
    statistics::vector<int> data(1000);
    for (auto _: state) {
        // This code gets timed
        data.quickSort();
    }
}

static void BM_statisticsVectorMergeSort(benchmark::State &state) {
    // Perform setup here
    statistics::vector<int> data(1000);
    for (auto _: state) {
        // This code gets timed
        data.mergeSort();
    }
}

// benchmarks, run on average 100 elements
BENCHMARK(BM_statisticsVectorBubbleSort);
BENCHMARK(BM_statisticsVectorQuickSort);
BENCHMARK(BM_statisticsVectorMergeSort);

BENCHMARK_MAIN();