#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

 // Parameterized constructor: creates a max heap from the given input.
  StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input){
    ConvertToHeap(input);
  }

  // Returns the parent of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetParent(int i){
    auto heap_size = size();
    auto parent = (i-1) / 2; 
    //base case: 
    if(i <= 0 || i >= size()){
        return Student("NO_NAME", INT_MIN); 
    }
    return data_[(parent)];
  }

  // Returns the left child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetLeft(int i){
    auto heap_size = size();
    auto left = (i * 2) + 1; 
    //base case
    if(left >= heap_size){
        return Student("NO_NAME", INT_MIN);
    }
    return data_[(left)];
  }

  // Returns the right child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetRight(int i){
    auto heap_size = size();
    auto right = (i * 2) + 2; 
    //base case 
     if(right >= heap_size){
        return Student("NO_NAME", INT_MIN);
    }
    return data_[(right)];
  }

  // Returns the index of the parent of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetParentIndex(int i){
    auto parent = (i-1) / 2; 
    if(i != 0){
        return parent; 
    }else{
        return INT_MAX; 
    }
  }

  // Returns the index of the left child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLeftIndex(int i){
    auto heap_size = size();
    auto left = (i * 2) + 1;
    if(left <= heap_size - 1){
        return left; 
    }else{
        return INT_MAX; 
    }
  }

  // Returns the index of the right child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetRightIndex(int i){
    auto heap_size = size();
    auto right = (i * 2) + 2;
    if(right <= heap_size - 1){
        return right; 
    }else{
        return INT_MAX; 
    }
  }

  // Returns the index of the largest child of a node given its index in the
  // tree. Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLargestChildIndex(int i){
   auto right = GetRight(i);
   auto left = GetLeft(i);
   auto index_left = GetLeftIndex(i);
   auto index_right = GetRightIndex(i);

   //base cases 
   if(index_right == INT_MAX && index_left == INT_MAX){
        return INT_MAX; 
   }else if(index_right == INT_MAX){
        return index_left; 
   }else if(index_left == INT_MAX){
        return index_right; 
   }
   //compare the grades of left and right children
   if(left.grade > right.grade){
        return index_left; //returns the index of the larger one
   }else{
        return index_right; //returns the index of the larger one if this is larger
   }
  }

//   // Returns true if the heap is empty and false otherwise.
//   bool StudentMaxHeap::empty() { return data_.empty(); };

//   // Returns the size of the heap.
//   int StudentMaxHeap::size() { return data_.size(); }

  // Returns the top of the heap. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::top(){
    if(!empty()){
        return data_[0]; //returns the top element 
    }else{
        return Student("NO_NAME", INT_MIN);
    }
  }

  // Adds a new Student to the heap.
  void StudentMaxHeap::push(const Student& student){
    auto heap_size = size();
    if(!empty()){
        data_.push_back(student); //add new student at the end of the heap
        TrickleUp(heap_size - 1); //trickle up student to its proper index
    }else{
        data_.push_back(student); //add new student to the empty heap
    }
  }

  // Removes the top. Returns
  // true if successful and false otherwise.
  bool StudentMaxHeap::pop(){
    if(!empty()){
        data_[0] = data_.back(); //swapped with the rightmost number 
        data_.pop_back(); //then element is removed from heap
        TrickleDown(0); //rearrange elements 
        return true; //return true if successful 
    }else{
        return false; 
    }
  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleUp(int i){
    while(i != 0){
        if(data_[i] > data_[GetParentIndex(i)]){ //makung sure it continues up until its no longer greater than parent
            swap(data_[i], data_[GetParentIndex(i)]);
            i = GetParentIndex(i);
        }else{
            return;
        }
    }
  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleDown(int i){
    auto large = GetLargestChildIndex(i);

    if(large == INT_MAX || data_[i] > data_[large]){
        return; 
    }else if(data_[i] < data_[large]){
        swap(data_[i], data_[large]);
        TrickleDown(large);
    }
  }

  // Converts the given input into a max heap and stores that into data_.
  void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input){
    data_ = input; 
    int data_size = static_cast<int>(size()); //ensuring that the value fits into the int
    for(int x = data_size / 2; x>= 0; x--){
        TrickleDown(x);
    }
  }

//-----------------------------------------------------------------------------
// TODO: Implement this function:
// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades. Use heap sort!
void HeapSort(std::vector<Student>& input){
    //base case
    if(input.empty()){
        return;
    }
    //creation of a heap using the constructor 
    StudentMaxHeap new_heap(input);
    std::vector<Student> output;  //temp vector
    //keep going until the heap is empty 
    while(!new_heap.empty()){
        output.push_back(new_heap.top()); //takes element from the top of the heap and puts it at the end
        new_heap.pop(); //removes the max number
    }
    input = output; 
    std::reverse(input.begin(), input.end()); //change the order to sort items in decending order
}