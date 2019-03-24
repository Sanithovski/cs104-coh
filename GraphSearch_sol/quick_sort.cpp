#include "quick_sort.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

void quick_sort_h(vector<int>& v, unsigned int start, unsigned int end) 
{
    if (start >= end) return;
    unsigned int pivot = select_pivot(start, end);

    int pivot_val = v[pivot];
    int temp = v[pivot];
    v[pivot] = v[end];
    v[end] = temp;

    unsigned int i = start, j = end-1;
    
    while (i < j) {
        while (i < j && v[i] <= pivot_val) {
            i++;
        }
        while (i < j && v[j] > pivot_val) {
            j--;
        }

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    if (v[i] > pivot_val) {
        temp = v[i];
        v[i] = v[end];
        v[end] = temp;
    }
    
    quick_sort_h(v, start, i);
    quick_sort_h(v, i+1, end);

}

void quick_sort(std::vector<int>& v) 
{
    // TODO
    // You may add helper function if needed

    quick_sort_h(v, 0, v.size()-1);
}


unsigned int select_pivot(unsigned int start, unsigned int end)
{
    if (start >= end) return start;
    srand(time(0));
    return rand() % (end-start+1) + start;
}

TEST_CASE("Small arrays", "[q_sort]")
{
    SECTION("Basic") {
        vector<int> v{1, 8, 4, 6, 3, 7, 5, 2};
        quick_sort(v);
        vector<int> ans{1, 2, 3, 4, 5, 6, 7, 8};
        REQUIRE(v == ans);
    }

    SECTION("Repeats") {
        vector<int> v{1, 3, 4, 1, 3, 2, 2, 4};
        quick_sort(v);
        vector<int> ans{1,1,2,2,3,3,4,4};
        REQUIRE(v == ans);
    }

    SECTION("In order") {
        vector<int> v;
        for (int i = -10; i < 11; i++) {
            v.push_back(i);
        }
        vector<int> w = v;
        quick_sort(v);
        REQUIRE(v == w);
    }
}

TEST_CASE("Randomized arrays", "[q_sort]")
{
    SECTION("Randomized") {
        vector<int> v;
        for (unsigned int i = 0; i < 100 + rand()%10000; i++) {
            v.push_back(rand()%10000);
        }
        vector<int> ans = v;
        quick_sort(v);
        sort(ans.begin(), ans.end());
        REQUIRE(v == ans);
    }
}