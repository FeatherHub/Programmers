#include <gtest/gtest.h>
#include <gtest/gtest-death-test.h>
#include <string>
#include <vector>

#include "120844.h"

TEST(CASE_1, Many_Elements) {
    const string right = "right";
    const string left = "left";

    EXPECT_EQ((vector<int> { 5, 1, 2, 3, 4 }), solution({ 1, 2, 3, 4, 5 }, right));
    EXPECT_EQ((vector<int> { 2, 3, 4, 5, 1 }), solution({ 1, 2, 3, 4, 5 }, left));
    EXPECT_EQ((vector<int> { 5, 1, 2, 3, 4 }), solution2({ 1, 2, 3, 4, 5 }, right));
    EXPECT_EQ((vector<int> { 2, 3, 4, 5, 1 }), solution2({ 1, 2, 3, 4, 5 }, left));
}

TEST(CASE_2, Single_Element) {
    const string right = "right";
    const string left = "left";

    EXPECT_EQ((vector<int> { 5 }), solution({ 5, 5 }, right));
    EXPECT_EQ((vector<int> { 2 }), solution({ 2 }, left));
    EXPECT_EQ((vector<int> { 5 }), solution2({ 5 }, right));
    EXPECT_EQ((vector<int> { 2 }), solution2({ 2 }, left));
}

TEST(CASE_3, Zero_Element) {
    const string right = "right";
    const string left = "left";

    EXPECT_EQ((vector<int> {}), solution({}, right));
    EXPECT_DEATH(solution2({}, right), "");
}