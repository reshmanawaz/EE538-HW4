#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

// //empty
TEST(q1, test1){
    std::vector<std::vector<int>> map = {};
    std::pair<int, int> x = {0,0};
    std::pair<int, int> y = {0,0};
    int output = FindNumberOfUniquePaths(map, x, y);
    EXPECT_EQ(output, 0);
}
// //start==end
TEST(q1, test2){
    std::vector<std::vector<int>> map = {
    {1,1,1}
    };
    std::pair<int, int> x = {0,1};
    std::pair<int, int> y = {0,1};
    int output = FindNumberOfUniquePaths(map, x, y);
    EXPECT_EQ(output, 1);
}

TEST(q1, test3){
    std::vector<std::vector<int>> map = {
    {1,1,1}};
    ASSERT_EQ(FindNumberOfUniquePaths(map, {0,0}, {0,2}), 1);
}

TEST(q1, test4){
    std::vector<std::vector<int>> map = {
    {1,1,1},
    {1,1,1}
    };
    ASSERT_EQ(FindNumberOfUniquePaths(map, {0,0}, {1,2}), 3);
}
TEST(q1, test5){
    std::vector<std::vector<int>> map = {
    {1,1,1},
    {1,0,1}
    };
    ASSERT_EQ(FindNumberOfUniquePaths(map, {0,0}, {1,2}), 1);
}
TEST(q1, test6){
    std::vector<std::vector<int>> map = {
    {1,1,1,1,0},
    };
    ASSERT_EQ(FindNumberOfUniquePaths(map, {0,0}, {0,4}), 0);
}

TEST(q1, test7){
    std::vector<std::vector<int>> map = {
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0}
    };
    ASSERT_EQ(FindNumberOfUniquePaths(map, {0,0}, {1,4}), 0);
}