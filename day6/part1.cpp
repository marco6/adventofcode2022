#include <cstddef>
#include <bit>
#include <iostream>
#include <bitset>

int main() {
    uint64_t counter = 0;
    char buffer[4] = { };

    for (size_t i = 0; i < 3 && std::cin >> buffer[i]; i++) {
        counter += (1ull << (buffer[i] - 'a'));
    }
    constexpr auto asd = 'z' - 'a';

    for (size_t i = 3; std::cin >> buffer[i & 0x3]; i++) {
        counter += (1ull << (buffer[i & 0x3] - 'a'));

        if (std::popcount(counter) == 4) {
            std::cout << (i+1) << std::endl;
            break;
        }

        counter -= (1ull << (buffer[(i + 1) & 0x3] - 'a'));
    }
}
