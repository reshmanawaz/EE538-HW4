#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/**
 * This function is used by Google Test. Don't touch!
 */
template <class T>
void PrintCollection(std::string_view name, T input, bool add_new_line = true) {
  if (!name.empty()) {
    std::cout << name << ": ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }";
  if (add_new_line) {
    std::cout << std::endl;
  }
}

template <class T>
void Print2dVector(std::string_view name, std::vector<std::vector<T>> input) {
  std::cout << name << ": {" << std::endl;
  for (size_t i = 0; i < input.size(); i++) {
    std::cout << "  {";
    for (size_t j = 0; j < input[0].size(); j++) {
      std::cout << input[i][j];
      if (j < input[0].size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "}" << std::endl;
}

//-----------------------------------------------------------------------------
// TODO:
/**
Given a map, represented by a n*m matrix of values 0 and 1,
a hiker must find a path from index [0][0] to [n-1][m-1].

The hiker can only travel to right, down, left, up.

It can only travel on 0 values. 1 values represent obstacles.

Return a path that takes the hiker from [0][0] to [n-1][m-1].

If there are multiple paths, you should return the path in which
when there is a choice, the precedence should be as follows:

1. Right (Highest precedence)
2. down
3. left
4. up (lowest precedence)

Return [-1,-1] if there is no path.

Example:

TEST(HikerPathTest, SimpleMaze) {
  vector<vector<int>> maze = {//
                              {0, 0, 0, 1},
                              {0, 1, 0, 1},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0}};

  vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
                                      {2, 2}, {2, 3}, {3, 3}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}


*/
std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze);
