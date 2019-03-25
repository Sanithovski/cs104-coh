# CS 104 COH Week #10 (Mar. 27)  
## Topics:  
* Dijsktra's Algorithm for Shortest path

## Task 1: Dijksta's Algorithm
* Files involved: dijkstra.cpp  
  
Given a graph represented in the adjacency matrix format, a starting node and an ending node, complete the Dijsktra's algorithm which computes the length of the shortest path between the start and the end nodes in the graph.

* The graph is given in the adjacency matrix. The entries in the table indicates the weight of the directed edge from the row index to the column index. For example, if
`M[2][3] = 5`, it means a directed edge connects node 2 to node 3 with a weight of 5.
* If no edges exist, the entry is filled with `-1`. **It is important to note that this doesn't mean the edge weight is -1 but simply means there are no edges in place.**
* To find the node with the smallest weight at each iteration, you can simply search through all the nodes and return the minimal value. This is less efficient but OK for this question.  
* Weight can only be a non-negative number. Dijsktra's Algorithm only works on a graph with non-negative weights.
* It is possible that two edges with opposite directions connect two nodes at the same time. This shouldn't affect the implementation of the Dijsktra's algorithm as long as you are implementing it correctly.
* You may write helper functions or include more STL libraries if needed.

## Task 2: Improve the algorithm using Priority Queue
During each iteration of the Dijsktra's algorithm, you need to find the node with the smallest weight to start updating the distance of other nodes. If you used to traditional way to find the smallest value, each iteration will take O(n) for this step. But since you've learnt that Heaps can achieve this goal in shorter time, you can replace this step using a heap.  
* The STL library has an implementation of priority queue: `<priority_queue>`. You can look up its usage on [CPP Reference](cppreference.com). If you have completed problem 2 in PA6 then you have your own Heap structure with customizable children count. You can use that as well (which is also a good way to test your solution).
* The adjacency matrix doesn't have an actual node structure. In order to use the priority queue you'll need to push the node index as well as its distance from start into the heap. To achieve that you may use a std::pair. It is included in the STL `<utility>` library. You should have been familiar with it when using iterators in std::map. You may also create a struct to store the node. Either way, you'll need to provide a custom Comparator for your priority queue to set the distance as the priority, not the Node index.
* We need to update the distance of each node from the start in each iteration, and we also need to make the same update in the Priority Queue. However, neither your Heap or the STL Priority Queue has a way to update or remove an arbitrary node within the queue. Instead, we can repeatedly push the nodes into the PQ. At the mean time, we maintain a "visited set" (or vector) to record which node we have visited in previous iterations. Therefore, whenever we extract a node from the heap, we will check if we have visited before and if we have, we just discard the node and extract the next one. This makes our algorithm a little bit less efficient, but in practice it is still faster than checking all nodes for each iteration.
* HackerRank has a similar question to implement the dijsktra's algorithm. However the problem statement is a little different: it requires you to return the distance from a given node to all other nodes in a vector. The input format is different as well, but it shouldn't be too difficult to convert to two problems. You can find it [here](https://www.hackerrank.com/challenges/dijkstrashortreach/problem). Try solving this with a modified `dijsktra` function if you have time, and test its correctness.  

## Task 3: Tree Sum
In the lab this week you implemented three tree traversal methods: Pre-order, Post-order and In-order. Now, use one of these traversal methods to solve the tree sum question:  
Each leaf node of the tree has a non-negative value in it, and all other nodes' values are initialized to be -1. Write a function to update the value stored inside all non-leaf nodes, so that each of these node's value becomes the sum of the values of its left child and right child. If a child is missing, if becomes the value of the existing child. (If a child pointer is NULL, then take it as 0).
* Try to apply the traversal function you wrote for the lab. Make a change to it so it can update the value variable stored in each node.
* By definition, the root node should contain the sum of all values stored in the leaf nodes. The pointer to the root will be passed in as the function argument. Do modifications on the original tree instead of creating a new one.

## Challenge:
The following question is outside the topics covered in CS 104. You can try it if you really have an interest in the data structure, or you are attending the programming contest.  
1. Following the ideas of Task 3. If I modify a value in one of the leave nodes, what is the time complexity to update the tree so it still meet the property above?
2. Suppose the tree is full (that is, each node in the tree has 0 or 2 children), it is possible to represent the values in the leaf nodes in an array, from left to right. Inspect the tree and the array, then give a description of the value stored in the non-leaf nodes in the tree: what do their values represent?   

** The Final Challenge**: Solve the ***Range Sum*** question below:  
We have an array arr[0 . . . n-1]. We should be able to  
1. Find the sum of elements from index l to r where 0 <= l <= r <= n-1
2. Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

It is fairly easy to solve the problem by just summing up the range in the original array. However, this would take `O(n)` to compute each sum. With more thinking you may find out that you can maintain another array, where the element at the i-th index is the sum of element 0 to i in the original array; however, this will cause your update operation to cost `O(n)` as a trade off. Think about this: is it possible to do both of them in `O(logn)`? Use ideas from Task 3 and the above two questions help you find out the answer.  

(This will be your first steps toward competitive programming. If you are participating the programming contest this Saturday, solving this problem can help a lot).
