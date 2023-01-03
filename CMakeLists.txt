cmake_minimum_required(VERSION 3.24)
project(cmake_test)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(folly REQUIRED)

add_executable(cmake_test main.cpp)
target_compile_features(cmake_test PRIVATE cxx_std_17)
target_link_libraries(cmake_test
        PRIVATE
        fmt::fmt
        range-v3::range-v3
        cxxopts::cxxopts
        Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util
        )
