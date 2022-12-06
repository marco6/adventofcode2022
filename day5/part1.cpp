#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>

int main() {
    std::vector<std::vector<char>> stacks;
    std::string line;

    if (std::getline(std::cin, line)) {
        stacks.resize((line.size() + 3) / 4);
        do {
            for (size_t i = 0; i * 4 < line.size(); i ++) {
                if (line[i * 4] == '[') {
                    stacks[i].insert(stacks[i].begin(), line[i * 4 + 1]);
                }
            }
        } while(std::getline(std::cin, line) && line.size());

        std::cout << "==" << line << std::endl;

        int count, from, to;

        while (scanf("move %d from %d to %d\n", &count, &from, &to) == 3) {
            while (count --> 0) {
                stacks[to - 1].push_back(stacks[from - 1].back());
                stacks[from - 1].pop_back();
            }
        }
    }

    for (auto& stack : stacks) {
        std::cout << stack.back();
    }

    std::cout << std::endl;
}
