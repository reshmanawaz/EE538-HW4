#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// TODO: Implement the following functions in q.cc.

// On an m x n grid, where m is the number of rows and n is the number of
// columns. We want to know how many unique paths exists from start point to the
// end point. We can only move to the right or to the bottom direction. If a
// grid entry has 1, it means we can move to that location, otherwise, not.
//
// Example:
// Input grid: {1, 1, 1}, start = (0,0), end = (0, 2).
// Output: 1

// Input grid: {1, 0, 1}, start = (0,0), end = (0, 2).
// Output: 0

// Input grid: {
// {1, 1, 1},
// {1, 1, 1}
// }
// start = (0,0), end = (1, 2).
// Output: 3

// Input grid: {
// {1, 1, 1},
// {1, 0, 1}
// }
// start = (0,0), end = (1, 2).
// Output: 1


// Hint: At each location in the graph we have two choices. Try to use this to
// write a recursive relationship.
int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid, const std::pair<int, int> start, const std::pair<int, int> end){
    //check if gridn is empty  
    if(grid.empty()){
        return 0; //no paths 
    }
    //x-y axis to show the rows and coloums 
    auto x = grid.size(); // rows 
    auto y = grid[0].size(); //coloums 

    //right and down initlization 
    std::pair<int, int> r(start.first, start.second +1);
    std::pair<int, int> d(start.first + 1, start.second);

    //check base cases for the xy axis 
    if(x == 0 || y == 0){
        return 0; 
    }else if(start.first < 0 || start.first >= x ){ //starting point 
        return 0;
    }else if(start.second < 0 || start.second >= y){
        return 0;
    }else if(grid[start.first][start.second] == 0){
        return 0;
    }else if(start == end){
        return 1; 
    }
    //moving down while using the same function to add the grid, newly created pair, and the end
    int down = FindNumberOfUniquePaths(grid, d, end);
    //moving right while using the same function to add the grid, newly created pair, and the end
    int right = FindNumberOfUniquePaths(grid, r, end);

    auto total = right + down; 
    return total; 
}