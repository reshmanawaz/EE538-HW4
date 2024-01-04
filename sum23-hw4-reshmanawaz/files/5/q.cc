#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Given a map, represented by a n*m matrix of values 0 and 1,
// a hiker must find a path from index [0][0] to [n-1][m-1].

// The hiker can only travel to right, down, left, up.

// It can only travel on 0 values. 1 values represent obstacles.

// Return a path that takes the hiker from [0][0] to [n-1][m-1].

// If there are multiple paths, you should return the path in which
// when there is a choice, the precedence should be as follows:

// 1. Right (Highest precedence)
// 2. down
// 3. left
// 4. up (lowest precedence)

// Return [-1,-1] if there is no path.

// Example:

// TEST(HikerPathTest, SimpleMaze) {
//   vector<vector<int>> maze = {//
//                               {0, 0, 0, 1},
//                               {0, 1, 0, 1},
//                               {0, 1, 0, 0},
//                               {0, 0, 1, 0}};

//   vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
//                                       {2, 2}, {2, 3}, {3, 3}};
//   vector<vector<int>> actualPath = HikerPath(maze);

//   EXPECT_EQ(expectedPath, actualPath);
// }

//new function 1: checking if valid or not valid x = row, y = coloumn 
bool valid_check(size_t x, size_t y, std::vector<std::vector<int>>& maze){
    if(x >= static_cast<int>(maze.size())){ //checks for the maze size 
        return false; 
    }else if(y >= static_cast<int>(maze[0].size())){ //checks for the maze size
        return false; 
    }else if(maze[x][y] != 0){ //makes sure the maze coordinate is not 0
        return false;
    }else if(maze[x][y] == -1){
        return false; 
    }else{
        return true; 
    }
}

//new function 2: DFS Function (depth first search)
bool DFS(std::vector<std::vector<int>>& maze, std::vector<std::vector<int>>& route, int x, int y){
    std::vector<std::vector<int>> direction = {
        {0,1}, {1,0}, {0,-1}, {-1,0} //right, left, up, down
    };
   
    if(x == maze.size() - 1 && y == maze[0].size() - 1){
        route.insert(route.begin(), {x,y}); //inserts coordinates x,y at the beginning of the route 
        return true; 
    }
    maze[x][y] = -1; //visted

    auto size = direction.size();
    //Goes through each direction in the direction vector 
    for (auto i = 0; i < size; i++){
        int x_new = x + direction[i][0];
        int y_new = y + direction[i][1];

        //used to check if the new directions are within bounds and making sense 
        if(valid_check(x_new, y_new, maze)){
            if(DFS(maze, route, x_new, y_new)){ //after visited, then it performs dfs
                route.insert(route.begin(), {x,y});
                return true;
            // }else{
            //     route.pop_back(); //dfs not leading to destination 
            }
            //if(!route.empty()) route.pop_back();
        }
    }
    return false; 
}

std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze){
    std::vector<std::vector<int>> route; //initialize an empty 2D vector
    //check if the maze is empty 
    if(maze.empty() || maze[0].empty() || maze[0][0] != 0){
        return {{-1, -1}}; //no solution exists 
    }
    maze[0][0] = -1; //top left cell 
    if(DFS(maze, route, 0, 0)){ //dfs starts at the top left cell 
        return route; 
    }else{
        return {{-1, -1}}; //no solution exists 
    }
}