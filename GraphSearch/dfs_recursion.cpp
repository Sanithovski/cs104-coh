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
    Node::cnt = 0;
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
    SECTION("Octopus") {
        Node A, B, C, D, E, F, G, H, I;
        A.neighbors = { &B, &D, &F, &H };
        B.neighbors = { &A, &C };
        C.neighbors = { &B };
        D.neighbors = { &A, &E };
        E.neighbors = { &D };
        F.neighbors = { &A, &G };
        G.neighbors = { &F };
        H.neighbors = { &A, &I };
        I.neighbors = { &H };

        REQUIRE(dfs_recursion(&A, &I) == true);
    }
}

TEST_CASE("Somewhat edge cases", "dfs_recursion")
{
    Node::cnt = 0;
    SECTION("Small loop") {
        Node A, B, C, D;
        A.neighbors = { &B, &C };
        B.neighbors = { &A, &C };
        C.neighbors = { &B, &C };

        REQUIRE(dfs_recursion(&A, &D) == true);
    }

    SECTION("Self-Loop") {
        Node A, B;
        A.neighbors = { &A };
        
        REQUIRE(dfs_recursion(&A, &B) == false);
    }
}
