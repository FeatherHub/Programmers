#pragma once

#include <gtest/gtest.h>

#include <vector>

#include "solution.h"

using namespace std;

TEST(P120835, AscendingOrder) {
  vector<int> v1 { 10, 20, 30, 40, 50 };
  vector<int> expected { 5, 4, 3, 2, 1 };

  EXPECT_EQ(solution(v1), expected);
  EXPECT_EQ(map_to_ranks(v1), expected);
}

TEST(P120835, DescendingOrder) {
  vector<int> v2 { 50, 40, 30, 20, 10 };
  vector<int> expected { 1, 2, 3, 4, 5 };

  EXPECT_EQ(solution(v2), expected);
  EXPECT_EQ(map_to_ranks(v2), expected);
}

TEST(P120835, MixedOrder) {
  vector<int> v3 { 50, 30, 40, 10, 20 };
  vector<int> expected { 1, 3, 2, 5, 4 };

  EXPECT_EQ(solution(v3), expected);
  EXPECT_EQ(map_to_ranks(v3), expected);
}

TEST(P120835, SingleElement) {
  vector<int> v { 42 };
  vector<int> expected { 1 };

  EXPECT_EQ(solution(v), expected);
  EXPECT_EQ(map_to_ranks(v), expected);
}
