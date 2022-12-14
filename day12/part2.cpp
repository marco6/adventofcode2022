#include <cstddef>
#include <cstdint>
#include <iostream>
#include <deque>
#include <string>
#include <tuple>
#include <vector>

int main() {
    std::vector<std::string> map;
    std::string line;

    size_t sx = std::string::npos, sy = 0, ex = std::string::npos, ey = 0;

    while(std::cin >> line) {
        if (sx == std::string::npos) {
            sx = line.find('S');
            sy++;
        }

        if (ex == std::string::npos) {
            ex = line.find('E');
            ey++;
        }

        map.push_back(std::move(line));
    }

    map[--sy][sx] = 'a';
    map[--ey][ex] = 'z';
    
    std::vector<std::vector<int>> steps(map.size(), std::vector<int>(map[0].size(), -1));

    // Dijkstra per i poveri: tutti gli archi sono di lunghezza 1, quindi degenera in una BFS del grafo.
    std::deque<std::tuple<int, int, int>> to_visit ={ { ex, ey, 0 } };
    int min_distance = map.size() * map[0].size();

    while (!to_visit.empty()) {
        auto [x, y, distance] = to_visit.front();
        if (steps[y][x] == -1) {
            if (map[y][x] == 'a') {
                min_distance = std::min(distance, min_distance);
            }
            steps[y][x] = distance;

            // Where can I go?

            // left
            if (x != 0) {
                if (map[y][x - 1] >= (map[y][x] - 1)) {
                    to_visit.push_back({ x - 1, y, distance + 1 });
                }
            }

            // right
            if ((x+1) < steps[0].size()) {
                if (map[y][x + 1] >= (map[y][x] - 1)) {
                    to_visit.push_back({ x + 1, y, distance + 1 });
                }
            }

            // up
            if (y != 0) {
                if (map[y-1][x] >= (map[y][x] - 1)) {
                    to_visit.push_back({ x, y - 1, distance + 1 });
                }
            }

            // down
            if ((y+1) < steps.size()) {
                if (map[y + 1][x] >= (map[y][x] - 1)) {
                    to_visit.push_back({ x, y + 1, distance + 1});
                }
            }
        }

        to_visit.pop_front();
    }

    std::cout << min_distance << std::endl;
}
