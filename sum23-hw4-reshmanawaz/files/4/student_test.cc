#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

//empty 
TEST(q4, test1){
    std::vector<Student> input = {};
    HeapSort(input);
    EXPECT_EQ(input.size(), 0);
}
//2 inputs 
TEST(q4, test2){
    std::vector<Student> input = {
        Student("Ali", 92),
        Student("Nawaz", 60)
        //Student("Dania", 100)
    };

    std::vector<Student> output = {
        Student("Nawaz", 60),
        Student("Ali", 92),
    };
    HeapSort(input);
    //std::reverse(input.begin(), input.end());
    EXPECT_EQ(input, output);
}
//inputs already sorted 
TEST(q4, test3){
    std::vector<Student> input = {
        Student("Nawaz", 60),
        Student("Reshma", 80),
        Student("Ali", 92),
    };

    std::vector<Student> output = {
        Student("Ali", 92),
        Student("Reshma", 80),
        Student("Nawaz", 60),
    };
    HeapSort(input);
    std::reverse(input.begin(), input.end());
    EXPECT_EQ(input, output);
}
//random inputs 
TEST(q4, test4){
    std::vector<Student> input = {
        Student("Nawaz", 60),
        Student("Reshma", 80),
        Student("Ali", 92),
        Student("Nawaz1", 78),
        Student("Nawaz2", 23),
        Student("Nawaz3", 10),
        Student("Nawaz4", 99),
    };

    std::vector<Student> output = {
        Student("Nawaz4", 99),
        Student("Ali", 92),
        Student("Reshma", 80),
        Student("Nawaz1", 78),
        Student("Nawaz", 60),
        Student("Nawaz2", 23),
        Student("Nawaz3", 10),
    };
    HeapSort(input);
    std::reverse(input.begin(), input.end());
    EXPECT_EQ(input, output);
}
