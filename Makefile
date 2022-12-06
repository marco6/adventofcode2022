run: part1 part2
	cat input.txt | ./part1 
	cat input.txt | ./part2 

.PHONY: run

part1: part1.cpp
	$(CXX) part1.cpp -o part1

part2: part2.cpp
	$(CXX) part2.cpp -o part2
