#include <iostream>
#include "../lib/inc/statistics.hpp"
#include <vector>
#include <folly/FBVector.h>
#include "glog/logging.h"

int main() {
    google::InitGoogleLogging("glog.log");
    FLAGS_alsologtostderr = true;
    FLAGS_log_dir = ".";

    // create a vector using statistics using 1000 random integers between 1 and 1000
    statistics::vector<int> data(1000);
    // log the vector using the overloaded << operator
    LOG(INFO) << data;
    // sort the vector
    data.mergeSort();
    // print the vector again
    std::cout << data << std::endl;
    // log the median of a vector
    LOG(INFO) << "Median: " << data.median();
    // initialize an empty vector
    statistics::vector<int> empty;
    // print the median of an empty vector
    //std::cout << "Median of an empty vector : " << empty.median() << std::endl;

    return 0;
}
