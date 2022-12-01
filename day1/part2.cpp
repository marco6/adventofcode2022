#include <iostream>
#include <string>

int main() {
    std::string line;

    long long int accumulator = 0, max[3] = {};

    while (std::getline(std::cin, line)) {
        if (line.size()) {
            accumulator += std::stoll(line);
        } else {
            for (auto& m : max) {
                if (m < accumulator) {
                    m = accumulator;
                    break;
                }
            }
            accumulator = 0;
        }
    }

    for (auto& m : max) {
        if (m < accumulator) {
            m = accumulator;
            break;
        }
    }

    std::cout << (max[0] + max[1] + max[2]) << std::endl;
}
