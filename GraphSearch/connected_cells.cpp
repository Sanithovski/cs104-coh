#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

/**
 * Return the size of the largest region in the given matrix.
 * @param matrix The given matrix.
 * @return The size of the largest region.
 */
int connectedCell(vector<vector<int> > matrix)
{
  // TODO: Complete this function
  // Problem statement available on HackerRank. When done, copy your code in this
  // function directly to the connectedCell function on HackerRank and submit
  // to see if your code passes all test cases.
  
  return 0;
}

TEST_CASE("Base Case", "[connected_cells]")
{
  ifstream ifile;
  ifstream ansfile;
  string base_dir("input/");
  string ans_dir("ans/");
  SECTION("Example Case") {
    for (int i = 1; i <= 2; i++) {
      string filename = base_dir + "test" + to_string(i) + ".txt";
      string ansfilename = ans_dir + "ans" + to_string(i) + ".txt";
      ifile.open(filename);
      ansfile.open(ansfilename);
      if (!ifile || !ansfile) {
        cerr << "Cannot open file for test: " << filename << " and "
             << ansfilename << endl;
        ansfile.clear();
        ifile.clear();
        REQUIRE(false);
      } else {
        int n, m;
        ifile >> n >> m;
        vector<vector<int> > matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            ifile >> matrix[i][j];
          }
        }
        
        int result = connectedCell(matrix);
        int answer;
        ansfile >> answer;
        ansfile.close();
        ifile.close();
        REQUIRE(result == answer);
      }
      
    }
  }
}
