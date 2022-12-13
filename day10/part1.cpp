#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>



int main() {
    std::string instruction;
    size_t counter = 0, strength = 0;
    int reg = 1;

    auto increase_counter = [&]() {
        switch(++counter) {
        case 20:
        case 60:
        case 100:
        case 140:
        case 180:
        case 220:
            strength += reg * counter;
        }
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

    std::cout << strength << std::endl;
}
