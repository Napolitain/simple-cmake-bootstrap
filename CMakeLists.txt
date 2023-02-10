cmake_minimum_required(VERSION 3.24)
project(cmake_bootstrap)

set(CMAKE_CXX_STANDARD 17)

# -DCMAKE_TOOLCHAIN_FILE=.../cmake-test/vcpkg/scripts/buildsystems/vcpkg.cmake

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(folly REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)
find_package(absl CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

add_executable(${PROJECT_NAME} app/main.cpp lib/inc/statistics.hpp lib/src/statistics.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        fmt::fmt
        range-v3::range-v3
        cxxopts::cxxopts
        Folly::folly Folly::folly_deps
        glog::glog
        )

add_executable(${PROJECT_NAME}_test test/performance/libraries_bm.cpp lib/inc/statistics.hpp lib/src/statistics.cpp test/functional/statistics_test.cpp)
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}_test
        PRIVATE
        fmt::fmt
        range-v3::range-v3
        cxxopts::cxxopts
        absl::container_memory
        absl::core_headers
        absl::hash_function_defaults
        absl::raw_hash_map
        absl::algorithm_container
        absl::memory
        Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util
        GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main
        benchmark::benchmark benchmark::benchmark_main
        )
