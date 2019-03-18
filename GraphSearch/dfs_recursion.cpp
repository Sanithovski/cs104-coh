/**
 * CS104 COH Week 8, DFS with Recursion - Skeleton
 * Author: Yizhou Sheng
 *
 */
#include <iostream>
#include "dfs_recursion.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


using namespace std;

bool dfs_recursion(Node* start, Node* end)
{
    // This line help you identify your order of search
    cout << start->id << endl;
    // TODO: Complete this function
    // Your implementation should not utilize an actual stack
    

    return false; // Change this line to return the actual value
}

TEST_CASE("Basic Test", "[dfs_recursion]")
{
    SECTION("Really basic positive case") {
        Node::cnt = 0;
        Node A, B, C, D;
        A.neighbors = { &B, &C };
        B.neighbors = { &A, &D };
        C.neighbors = { &A, &D };
        D.neighbors = { &B, &C };
        REQUIRE(dfs_recursion(&A, &D) == true);
    }
    SECTION("Really basic negative case") {
        Node::cnt = 0;
        Node A, B, C, D; 
        A.neighbors = { &B };
        B.neighbors = { &A, &C };
        C.neighbors = { &B };
        REQUIRE(dfs_recursion(&A, &D) == false);
    }
}
