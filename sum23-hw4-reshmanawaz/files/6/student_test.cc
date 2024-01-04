#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(q6, t1) {
    std::vector<std::vector<char>> input = {
        {'1', '1', '1', '1'},
        {'1', '0', '0', '1'},
        {'1', '0', '0', '0'},
        {'1', '1', '1', '1'}
    };
    ASSERT_EQ(NumConnectedComponents(input), 1);
}

TEST(q6, t2) {
    std::vector<std::vector<char>> input = {
        {'1', '1', '1', '1'},
        {'0', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '1', '1'}
    };
    ASSERT_EQ(NumConnectedComponents(input), 2);
}

TEST(q6, t3) {
    std::vector<std::vector<char>> input = {
        {'1', '1', '1', '1'},
        {'0', '0', '0', '1'},
        {'1', '0', '0', '0'},
        {'0', '1', '1', '1'}
    };
    ASSERT_EQ(NumConnectedComponents(input), 3);
}


