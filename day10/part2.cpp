#include <cstddef>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <string>



int main() {
    std::string instruction;
    size_t counter = 0;
    int reg = 1;

    char screen[6][41] = {};

    auto increase_counter = [&]() {
        int y = counter / 40;
        int x = counter % 40;
        if (std::abs(reg - x) <= 1) {
            screen[y][x] = '#';
        } else {
            screen[y][x] = '.';
        }
        ++counter;
    };

    while (std::cin >> instruction) {
        increase_counter();

        if (instruction == "addx") {
            int op;
            std::cin >> op;

            increase_counter();
            reg += op;
        }
    }

    for (auto& line : screen) {
        std::cout << line << std::endl;
    }
}
