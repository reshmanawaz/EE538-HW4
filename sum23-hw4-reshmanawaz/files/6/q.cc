#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//-----------------------------------------------------------------------------
// TODO:
/*
Given a 2D grid of characters, find the number of connected components in the
grid. A connected component is a group of cells with value '1' that are all
connected to each other by horizontal or vertical lines.

Examples:

Input:
1 1 1 1
1 0 0 1
1 0 0 0
1 1 1 1
Output:
1

Input:
1 1 1 1
0 0 0 0
0 0 0 0
1 1 1 1
Output:
2

Input:
1 1 1 1
0 0 0 1
1 0 0 0
0 1 1 1
Output:
3

*/

//new function: DFS Function (depth first search)
bool DFS(std::vector<std::vector<char>>& maze, std::vector<std::vector<bool>>& check, int x, int y){
    std::vector<std::vector<int>> direction = {
        {0,1}, {1,0}, {0,-1}, {-1,0} //right, left, up, down
    };
    int a = maze.size();
    int b = maze[0].size();
    maze[x][y] = true; //visted

    auto size = direction.size();
    //Goes through each direction in the direction vector to check for adjacent cells 
    for (auto i = 0; i < size-1; i++){
        int x_new = x + direction[i][0];
        int y_new = y + direction[i][1];
        //checking bounds, if cells have been visited, and if the paths match
        if(x_new >= 0 && x_new < a && y_new >= 0 && y_new < b && !check[x_new][y_new] && maze[x_new][y_new] == '1'){
            DFS(maze, check, x_new, y_new);
        }
    }
}


int NumConnectedComponents(std::vector<std::vector<char>>& maze){
    if(maze.empty()){ //base case if maze empty 
        return 0; 
    }
    //dimensions of the maze 
    int a = maze.size();
    int b = maze[0].size();
    int count = 0;  //number of connections 
    std::vector<std::vector<bool>> check; 
    check.resize(a, std::vector<bool>(b, false)); //same size as the maze and setting values to false as default 
    int i = 0;
    int j = 0; 
    while(i < a){
        j = 0;
        while(j < b){
            if(maze[i][j] == '1' && !check[i][j]){ //checking for if the cell is connected and if it hasnt been visited yet 
                count++;
                DFS(maze, check, i, j); //mark cell as visited
            }
            j++;
        } 
        i++;
    }
    return count; //num of connected cells in the maze
}