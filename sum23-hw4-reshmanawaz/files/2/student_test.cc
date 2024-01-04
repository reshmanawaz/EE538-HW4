#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
//IsBidirectional
TEST(q3, t2) {
    std::map<int, std::set<int>> adjacency_list = {
        {0, {1, 3}},
        {1, {0, 2}},
    };
    Graph g(adjacency_list);  
    auto output = g.IsBidirectional();
    bool expected_output = false; 
    EXPECT_EQ(output, expected_output);
}
//HasCycle
TEST(q3, t3) {
    std::map<int, std::set<int>> adjacency_list = {
        {0, {1, 3}},
        {1, {0, 2}},
    };
    Graph g(adjacency_list);  
    auto output = g.HasCycle();
    bool expected_output = true; 
    EXPECT_EQ(output, expected_output);
}
//ReachesACycleHelper
TEST(q3, t4) {
    std::map<int, std::set<int>> adjacency_list = {
        {0, {1}},
        {1, {0, 2}},
        {2, {1}},
    };
    Graph g(adjacency_list);  
    std::map<int, NodeStatus> x; 
    auto output = g.ReachesACycleHelper(0, x);
    bool expected_output = true; 
    EXPECT_EQ(output, expected_output);
}