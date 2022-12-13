#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>


int main() {
    std::vector<std::vector<uint8_t>> grid;
    std::string current;
    while (std::cin >> current) {
        grid.emplace_back(current.begin(), current.end());
    }
    
    size_t max_score = 0;

    for (size_t i = 1; i < grid.size() - 1; ++i) {
        for (size_t j = 1; j < grid.size() - 1; ++j) {
            auto height = grid[i][j];

            size_t count, score = 1;
            // right
            count = 0;
            for (size_t x = j + 1; x < grid.size(); ++x) {
                ++count;
                if (grid[i][x] >= height) {
                    break;
                }
            }
            score *= count;

            // down
            count = 0;
            for (size_t y = i + 1; y < grid.size(); ++y) {
                ++count;
                if (grid[y][j] >= height) {
                    break;;
                }
            }
            score *= count;

            // left
            count = 0;
            for (size_t x = j; x > 0; --x) {
                ++count;
                if (grid[i][x - 1] >= height) {
                    break;
                }
            }
            score *= count;

            // up
            count = 0;
            for (size_t y = i; y > 0; --y) {
                ++count;
                if (grid[y - 1][j] >= height) {
                    break;
                }
            }
            score *= count;

            max_score = std::max(max_score, score);
        }
    }

    std::cout << max_score << std::endl;
}
