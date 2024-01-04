#include "q.h"
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include<algorithm> 
#include <climits>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//-----------------------------------------------------------------------------
  // TODO: Implement the following functions.
  //-----------------------------------------------------------------------------
  // Performs DFS search from root and returns the visited nodes in DFS order.
  // When there is a choice, the node with lower value should be visited first.

  std::vector<int> Graph::DFS(int root){
    std::map<int, bool> new_marks;
    std::vector<int> new_visited;
    DFS_helper(root, new_marks, new_visited);
    return new_visited;
  }

  // Performs DFS search on all nodes and returns the visited nodes in DFS
  // order. When there is a choice, the node with lower value should be visited
  // first. Note that this function does not take any inputs.
  std::vector<int> Graph::DFSAll(){
    std::map<int, bool> new_marks;
    std::vector<int> new_visited;
    for(auto child : adjacency_list_){
        if(new_marks[child.first] != 1){
            DFS_helper(child.first, new_marks, new_visited);
        }
    }
    return new_visited;
  }

  // Performs BFS search from root and returns a result of type BFSReturnValue,
  // which has the following:
  // 1. result.visited (vector): visited nodes in BFS order.
  // 2. result.path (map): a map of node i to a vector, where the vector is the
  // shortest path from root to i.
  // 3. result.distance (vector): element i represents the shortest distance
  // from root to node i.
  //
  // Assume root is a valid node in the graph.
  BFSReturnValue Graph::BFS(int root){
    BFSReturnValue output; 
    std::map<int, std::vector<int>> path; //shortest paths in the map 
    std::vector<int> visited(adjacency_list_.size(), false); //for visited nodes
    std::vector<int> distance(adjacency_list_.size(), INT_MAX);  
    std::vector<int> previous(adjacency_list_.size(), -1); 

    BFS_helper(root, distance, previous, visited); 
    output.distance = distance; //distance info stored 
    output.path = path; //path info stored 

    auto size = adjacency_list_.size();
    //shortest path from node to root 
    for(size_t i = 0; i < size; i++){
      if(distance[i] != INT_MAX){
        int j = i; 
        output.path[i].push_back(i);
        while(j != root){
          j = previous[j];
          output.path[i].push_back(j);
        }
        std::reverse(output.path[i].begin(), output.path[i].end());
      }
    }
    //adding all visited nodes to the vector
    for(size_t i=0; i < visited.size(); i++){
      if(visited[i]){
        output.visited.push_back(i);
      }
    }
    return output; 
  }

  // Returns true if there is at least one path between nodes i and j.
  // Assume i, j are valid nodes in the graph.
  bool Graph::IsPathBetweenNodes(int i, int j){
    std::map<int, bool> new_marks;
    std::vector<int> new_visited;
    DFS_helper(i, new_marks, new_visited);
    return new_marks[j];
  }

  // Returns true if the graph is bidirectional. A bidirectional graph is a
  // graph in which if edge (i,j) is in E, then the edge (j,i) is also in E.
  // An empty graph is considered bidirectional.
  // A graph of a single node is considered bidirectional.
  bool Graph::IsBidirectional(){
    for(auto x : adjacency_list_){ //outer loop 
      for(auto y : x.second){ // inner loop = iterate over each adjacent node 
        auto next = adjacency_list_[y]; // gets nodes adjacent to node
        if(adjacency_list_[y].count(x.first) == 0){
          return false;
        }
      }
    }
    return true; 
  }

  // Returns true if the graph is connected, i.e. if we start from each node, we
  // can get to any other node.
  bool Graph::IsConnected(){
    std::map<int, bool> new_marks;
    std::vector<int> new_visited;
    if(!adjacency_list_.empty()){
      DFS_helper(adjacency_list_.begin()->first, new_marks, new_visited);
      }
    if(new_marks.size() != adjacency_list_.size()){
      return false;
      }
      return true; 
  }

  // Returns true if start_node can reach a cycle
  bool Graph::ReachesACycle(int start_node){
    std::map<int, NodeStatus> x; 
    return ReachesACycleHelper(start_node, x);
  }

  // Returns true if the graph has any cycles
  bool Graph::HasCycle(){
    std::map<int, NodeStatus> x; 
    for(auto pair : adjacency_list_){
      int node = pair.first;
      //checking if node has not been checked 
      if(x[node] == NodeStatus::NotVisited){
        if(ReachesACycleHelper(node, x)){
          return true; //cycle found
        }
      }
    }
    return false; 
  }

  // Helper function for ReachesACycle
  bool Graph::ReachesACycleHelper(int start_node, std::map<int, NodeStatus> &status){
    std::stack<int> x;
    x.push(start_node);
    status[start_node] = NodeStatus::Visiting;
    
    while(!x.empty()){
      int front = x.top();
      bool finished = true; 

      //checking the neighbors 
      for(auto i : adjacency_list_[front]){
        if(status[i] == NodeStatus::Visited){
          continue; 
        }else if(status[i] == NodeStatus::Visiting){
          return true; 
        }else{
          x.push(i);
          status[i] = NodeStatus::Visiting;
          finished = false; 
          break; 
        }
      }
      //marking node as finished after being visited 
      if(finished){
        status[front] = NodeStatus::Visited;
        x.pop();
      }
    }
    return false; 
  }

  // Optionally you can implement and use these functions.
  void Graph::DFS_helper(int root, std::map<int, bool> &marks, std::vector<int> &visited){
    //base case 
    if(adjacency_list_.find(root) == adjacency_list_.end()){
      return; 
    }
    marks[root] = 1; 
    visited.push_back(root);
    //traversing
    for(auto child : adjacency_list_[root]){
        if(marks[child] != 1){
            DFS_helper(child, marks, visited);
        }
    }
  }

  void Graph::BFS_helper(int root, std::vector<int> &distance, std::vector<int> &previous, std::vector<int> &visited){
     //base case 
    if(adjacency_list_.find(root) == adjacency_list_.end()){
      return; 
    }
    std::queue<int> q; //new queue
    q.push(root); //starting point

    visited[root] = true; //root = visited
    distance[root] = 0;  //distance from root = 0

    while(!q.empty()){
      int front = q.front(); //node at front
      q.pop(); //take the node out of the queue
   
      //traversing
      for(auto x : adjacency_list_[front]){
        if(!visited[x]){
          q.push(x);
          visited[x] = true;
          distance[x] = distance[front] +1;
          previous[x] = front;
        }
      }
    }
  }