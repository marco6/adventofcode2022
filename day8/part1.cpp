#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

struct tree {
    bool visible: 1;
    uint8_t height : 7;

    tree(uint8_t height) : visible(0), height(height) {}
};

int main() {
    std::vector<std::vector<tree>> grid;
    std::string current;
    while (std::cin >> current) {
        grid.emplace_back(current.begin(), current.end());
    }
    
    std::cout << std::endl;

    for (size_t i = 0; i < grid.size(); i++) {
        uint8_t left = 0, right = 0, top = 0, bottom = 0;
        for (size_t j = 0; j < grid.size(); j++) {

            // left to right
            if (grid[i][j].height > left) {
                left = grid[i][j].height;
                grid[i][j].visible = true;
            }

            // right to left
            if (grid[i][grid.size() - 1 - j].height > right) {
                right = grid[i][grid.size() - 1 - j].height;
                grid[i][grid.size() - 1 - j].visible = true;
            }

            // top to bottom
            if (grid[j][i].height > top) {
                top = grid[j][i].height;
                grid[j][i].visible = true;
            }

            // bottom to top
            if (grid[grid.size() - 1 - j][i].height > bottom) {
                bottom = grid[grid.size() - 1 - j][i].height;
                grid[grid.size() - 1 - j][i].visible = true;
            }
        }
    }

    size_t count = 0;

    for (auto& line : grid) {
        for (auto& t : line) {
            count += t.visible == true;
        }
    }

    std::cout << count << std::endl;
}
