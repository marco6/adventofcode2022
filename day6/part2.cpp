#include <cstddef>
#include <bit>
#include <iostream>
#include <bitset>

int main() {
    uint64_t counter = 0;
    char buffer[14] = { };

    for (size_t i = 0; i < 13 && std::cin >> buffer[i]; i++) {
        counter += (1ull << (buffer[i] - 'a'));
    }
    constexpr auto asd = 'z' - 'a';

    for (size_t i = 13; std::cin >> buffer[i % 14]; i++) {
        counter += (1ull << (buffer[i % 14] - 'a'));

        if (std::popcount(counter) == 14) {
            std::cout << (i+1) << std::endl;
            break;
        }

        counter -= (1ull << (buffer[(i + 1) % 14] - 'a'));
    }
}
