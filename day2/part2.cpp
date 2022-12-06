#include <iostream>


constexpr unsigned char scores[][3] {
    { 3, 6, 0 },
    { 0, 3, 6 },
    { 6, 0, 3 }    
};

long long int score(int op, int me) {
    return scores[op][me];
}

long long int score(int me) {
    return me + 1;
}



int main() {
    char op, me;
    long long int points = 0;
    while (std::cin >> op && std::cin >> me) {
        int op_move = op - 'A';
        int me_move = (op_move + (me - 'Y' + 3)) % 3;
        points += score(me_move) + score(op_move, me_move);
    }

    std::cout << points << std::endl;
}
