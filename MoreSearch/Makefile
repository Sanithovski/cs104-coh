COMPILE = g++ -g -Wall -std=c++11

all: tests
	
tests: dijkstra
	
dijkstra: dijkstra.cpp catch.hpp
	$(COMPILE) $< -o $@
	
clean:
	rm -f dijsktra *.exe *.o
	rm -r *.dSYM
