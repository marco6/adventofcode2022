#include <cstddef>
#include <iostream>
#include <utility>
#include <bit>

constexpr int priority(char c) {
    constexpr auto a = (int)'A';
    if (c > 'a') {
        return c - 'a' + 1;
    } else {
        return c - 'A' + 27;
    }
}

int main() {
    std::string line;
    long long int result = 0;
    while (std::getline(std::cin, line)) {
        uint64_t left = 0, right = 0;

        for (size_t i = 0; i < line.size() / 2; i++) {
            left |= 1ull << priority(line[i]);
            right |= 1ull << priority(line[line.size() - i - 1]);
        }

        result += std::countr_zero(left & right);
    }

    std::cout << result << std::endl;
}
