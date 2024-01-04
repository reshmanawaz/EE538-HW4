#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

// TEST(q3, test1){
//     std::vector<int> input = {{1, 10, 5, 4, 8, 9}};
//     int k = 2; 
//     std::vector<int> output = ProductOfKHighestNumbers(input, k);
//     std::vector<int> given_output = {10, 50, 50, 80, 90};
//     EXPECT_EQ(given_output, output);
// }
//size < k
TEST(q3, test2){
    std::vector<int> input = {1, 10};
    int k = 3; 
    std::vector<int> output = ProductOfKHighestNumbers(input, k);
    std::vector<int> given_output = {50, 200, 400, 720};
    EXPECT_TRUE(output.empty());
    std::cout << "Size < K" << std::endl; 
}
TEST(q3, test3){
    std::vector<int> input = {1, 10, 5};
    int k = 3; 
    std::vector<int> output = ProductOfKHighestNumbers(input, k);
    std::vector<int> given_output = {50};
    EXPECT_EQ(given_output, output);
}
TEST(q3, test4){
    std::vector<int> input = {1, 10, 5, 4};
    int k = 3; 
    std::vector<int> output = ProductOfKHighestNumbers(input, k);
    std::vector<int> given_output = {50, 200};
    EXPECT_EQ(given_output, output);
}
TEST(q3, test5){
    std::vector<int> input = {1, 10, 5, 4, 8};
    int k = 1; 
    std::vector<int> output = ProductOfKHighestNumbers(input, k);
    std::vector<int> given_output = {1, 10, 5, 4, 8};
    EXPECT_EQ(given_output, output);
}
