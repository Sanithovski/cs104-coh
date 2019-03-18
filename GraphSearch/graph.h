#ifndef GRAPH_NH
#define GRAPH_NH
#include <vector>


/**
 * The simple definition of a graph structure using adjacency list
 */
struct Node
{
    static unsigned int cnt;
    unsigned int id;
    std::vector<Node*> neighbors;
    
    Node() {
      id = cnt++;
    }
};

unsigned int Node::cnt = 0;

#endif
