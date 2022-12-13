#include <cstddef>
#include <cstdint>
#include <iostream>
#include <bitset>
#include <string>

constexpr std::size_t max_size = 4096;

int p2(int x) { return x * x;}

class point {
    friend class grid;
    int x{max_size / 2}, y{max_size / 2};
public:
    void move(char dir) {
        switch (dir) {
        case 'U': y++; break;
        case 'R': x++; break;
        case 'D': y--; break;
        case 'L': x--; break;
        }
    }

    void follow(const point& p) {
        // Only when distant enough
        int xmove = p.x - x, ymove = p.y - y;
        if ((p2(xmove) + p2(ymove)) >= 4) {
            // cryptic way to force the module of the movement to be 1
            x += xmove - xmove / 2; 
            y += ymove - ymove / 2;
        }
    }
};


class grid {
    std::bitset<max_size * max_size> storage{};
public:
    auto operator[] (const point& p) {
        return storage[p.x * max_size + p.y];
    }

    auto count() const {
        return storage.count();
    }
};

int main() {
    grid g;

    char direction;
    size_t steps;

    point knots[10]{}, &head = knots[0], &tail = knots[9];

    while (std::cin >> direction >> steps) {
        while(steps --> 0) {
            head.move(direction);
            for (size_t i = 1; i < 10; i++) {
                knots[i].follow(knots[i - 1]);
            }
            g[tail] = true;
        }
    }

    std::cout << g.count() << std::endl;
}
