.PHONY: all Main test clean valgrind

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

all: Main test

main_exec: main.cpp SquareMat.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp SquareMat.cpp

test_runner_exec: test_SquareMat.cpp SquareMat.cpp
	$(CXX) $(CXXFLAGS) -o test_runner test_SquareMat.cpp SquareMat.cpp

Main: main_exec
	@echo "========== Running Main =========="
	./main

test: test_runner_exec
	@echo "========== Running Tests =========="
	./test_runner

clean:
	rm -f main test_runner *.o

valgrind: main_exec test_runner_exec
	@echo "========== Valgrind Main =========="
	valgrind ./main
	@echo "========== Valgrind Test =========="
	valgrind ./test_runner
