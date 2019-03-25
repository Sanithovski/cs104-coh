#ifndef GRAPH_NH
#define GRAPH_NH
#include <vector>


/**
 * The simple definition of a graph structure using adjacency list
 */
struct Node
{
    Node* left;
    Node* parent; // Opetional
    Node* right;
    int val;
    
    Node(Node* l, Node* r, int v)
    : left(l), right(r), val(v)
    {}
};



#endif
