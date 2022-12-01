#include <iostream>
#include <string>

int main() {
    std::string line;

    long long int accumulator = 0, max = 0;

    while (std::getline(std::cin, line)) {
        if (line.size()) {
            accumulator += std::stoll(line);
        } else {
            max = std::max(max, accumulator);
            accumulator = 0;
        }
    }

    max = std::max(max, accumulator);

    std::cout << max << std::endl;
}
