//
// Created by Maxime Boucher on 14/01/2023.
//

#include "../../lib/inc/statistics.hpp"
#include "vector"
#include "gtest/gtest.h"

TEST(StatisticsTest, MeanTest) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    EXPECT_EQ(statistics::mean(data), 3);
}
