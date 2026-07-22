#pragma once

#include <gtest/gtest.h>
#include <string>
#include "p120853.h"
#include "p120853_v2.h"
#include "p120853_v3.h"

using namespace std;
TEST(test_p120853, basic) {
    string s{ "123 Z 456" };
    int o{ 456 };

    EXPECT_EQ((v1::solution(s)), (o));
    EXPECT_EQ((v2::solution(s)), (o));
    EXPECT_EQ((v3::solution(s)), (o));
}
