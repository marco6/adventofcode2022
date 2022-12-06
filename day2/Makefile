run: run-part1 run-part2

.PHONY: run

run-part1: part1
	cat input.txt | ./part1 

run-part2: part2
	cat input.txt | ./part2

part1: part1.cpp
	$(CXX) part1.cpp -std=c++20 -o part1

part2: part2.cpp
	$(CXX) part2.cpp -std=c++20 -o part2
