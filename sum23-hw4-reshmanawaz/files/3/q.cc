#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/**
 * Given a vector of integers, we want to produce the product of the current 
 * highest k > 0 of these numbers. If the input vector size is less than k,
 * then the output should be empty. The size of the output vector is equal to
 *  `input.size() - k + 1`.
 *
 * Example:
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 3
 * Output: {50, 200, 400, 720}
 * explanation: 
 * 
 * 1 * 10 * 5 = 50, (1, 10, 5 are the larggest ones in {1, 10, 5})
 * 10 * 5 * 4 = 200, (10, 5, 4 are the larggest ones in {1, 10, 5, 4})
 * 10 * 5 * 8 = 400, (10, 5, 8 are the larggest ones in {1, 10, 5, 4, 8})
 * 10 * 8 * 9 = 720 (10, 8, 9 are the larggest ones in {1, 10, 5, 4, 8, 9})
 *
 * input = {1, 10, 5, 4, 8, 9}, k = 13
 * Output: {}
 */

std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k){
    auto size = input.size();
    std::vector<int> output;

    //base case: empty vector
    if(size < k){
        return output; //which would be an empty vector 
    }
    auto mult = 1; 
    //map, priority queue, deque 
    std::priority_queue<int> new_q;
    std::deque<int> new_d;
    std::unordered_map<int, int> map;  //will be used to count the number of times each num appears so it is easier to increment and decrement 
    

    //used to calculate the first set of k elements 
    for(auto x = 0; x < k; x++){
        new_q.push(input[x]);
        new_d.push_back(input[x]);
        mult = mult * input[x];
        map[input[x]]++; //increment the value tagged to input[x]
    }
    output.push_back(mult); //add the result to the output vector

    for(int x = k; x < size; x++){
        new_d.push_back(input[x]);
        new_q.push(input[x]);
        mult = mult * input[x]; //mult w the new element 
        map[input[x]]++; //increment the value tagged to input[x]
 
        while(map[new_q.top()] != 1){
            map[new_q.top()]--; //decrements val associated w the key
            new_q.pop();
        }
        mult = mult / new_d.front(); //divide prod by the element removed 
        map[new_d.front()]--;
        new_d.pop_front(); 
        output.push_back(mult); //add prod to output
    }
    return output; 
}