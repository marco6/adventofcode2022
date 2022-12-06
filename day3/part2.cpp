#include <cstddef>
#include <iostream>
#include <string>
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

bool get_mask(uint64_t& mask) {
    mask = 0;
    std::string line;
    if (std::getline(std::cin, line)) {
        for (auto c : line) {
            mask |= 1ull << priority(c);
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string line;
    long long int result = 0;
    uint64_t m1, m2, m3;
    while (get_mask(m1) && get_mask(m2) && get_mask(m3)) {
        result += std::countr_zero(m1 & m2 & m3);
    }

    std::cout << result << std::endl;
}
