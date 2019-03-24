COMPILE = g++ -g -Wall -std=c++11

all: test

test: dfs_recursion quick_sort

dfs_recursion: dfs_recursion.cpp dfs_recursion.h graph.h catch.hpp
	$(COMPILE) $< -o $@

quick_sort: quick_sort.cpp quick_sort.h catch.hpp
	$(COMPILE) $< -o $@

clean: 
	rm -f quick_sort dfs_recursion *.exe 