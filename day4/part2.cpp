#include <cstddef>
#include <iostream>
#include <utility>
#include <bit>

int main() {
    int al, ah, bl, bh;
    int result = 0;

    while (scanf("%d-%d,%d-%d", &al, &ah, &bl, &bh) == 4) {
        result += al <= bh && bl <= ah;;
    }

    std::cout << result << std::endl;
}
