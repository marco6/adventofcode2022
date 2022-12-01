run: part1 part2
	cat part1.txt | ./part1 
	cat part2.txt | ./part2 

.PHONY: run

part1: part1.cpp
	$(CXX) part1.cpp -o part1

part2: part2.cpp
	$(CXX) part2.cpp -o part2
