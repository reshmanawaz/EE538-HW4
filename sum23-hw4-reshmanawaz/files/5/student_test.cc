#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

//given test case
TEST(q5, test1) {
  vector<vector<int>> maze = {//
                              {0, 0, 0, 1},
                              {0, 1, 0, 1},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0}};

  vector<vector<int>> output = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
                                      {2, 2}, {2, 3}, {3, 3}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(output, actualPath);
}
TEST(q5, test2) {
    std::vector<std::vector<int>> maze = {{0, 0, -1, 0},
                                          {-1, -1, 0, 0},
                                          {0, 0, 0, 0}};
    std::vector<std::vector<int>> output = {{-1, -1}};
    ASSERT_EQ(HikerPath(maze), output);
}
//empty
TEST(q5, test3) {
    std::vector<std::vector<int>> maze = {};
    std::vector<std::vector<int>> output = {{-1, -1}};
    ASSERT_EQ(HikerPath(maze), output);
}

//0
TEST(q5, test4) {
    std::vector<std::vector<int>> maze = {{0}};
    std::vector<std::vector<int>> output = {{0, 0}};
    ASSERT_EQ(HikerPath(maze), output);
}