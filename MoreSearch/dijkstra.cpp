#include <iostream>
#include <vector>
#include <fstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;


/**
 * Run the dijsktra's algorithm on the given graph, represented by an adjacency adj_matrix
 * @param adj_matrx Graph representation given in adjacency matrix form
 * @param start The starting node
 * @param end The target node for the search
 * @return The length of the shortest path between start and end in the graph
 */
unsigned int dijsktra(vector<vector<int> > adj_matrix, unsigned int start, unsigned int end)
{
  // TODO: implement this function
  return 0;
}

TEST_CASE("Basic Test for Dijksta", "[dijkstra]")
{
  string input_dir = "input/input";
  ifstream ifile;
  
  vector<vector<vector<int> > > tests;
  
  for (unsigned int i = 1; i <= 5; i++) {
    ifile.open(input_dir + to_string(i) + ".txt");
    if (ifile.fail()) {
      cerr << "Cannot open file " << input_dir + to_string(i) + ".txt" << endl;
      REQUIRE(false);
    }
    int n, m;
    ifile >> n;
    ifile >> m;
    vector<vector<int> > curr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ifile >> curr[i][j];
        if (!ifile) {
          cerr << "Error reading file" << input_dir + to_string(i) + ".txt" << endl;
          cerr << "\terror at cell (" << i << "," << j << ")" << endl;
          REQUIRE(false);
        }
      }
    }
    
    ifile.close();
    tests.push_back(curr);
  }
  
  SECTION("Base 1: Two paths") {
    REQUIRE(dijsktra(tests[0], 0, 5) == 13);
    tests.clear();
  }
  
  SECTION("Base 2: Detour") {
    REQUIRE(dijsktra(tests[1], 0, 4) == 9);
    tests.clear();
  }
  SECTION("Base 3: Complicated graphs") {
    REQUIRE(dijsktra(tests[2], 0, 5) == 8);
    tests.clear();
  }
  SECTION("Double edges") {
    REQUIRE(dijsktra(tests[3], 0, 3) == 8);
    tests.clear();
  }
  SECTION("With 0 weights") {
    REQUIRE(dijsktra(tests[4], 0, 3) == 3);
    tests.clear();
  }
  
}
