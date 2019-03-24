#ifndef DFS_RECUR
#define DFS_RECUR
#include "graph.h"

/**
 * Decide if the two nodes are connected within the given graph
 * @param start The starting node of search
 * @param end The target of the search
 * @return true if the two nodes are connected, false otherwise
 */
bool dfs_recursion(Node* start, Node* end);


#endif