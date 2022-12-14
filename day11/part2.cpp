#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef long long (*operation)(long long, long long);


long long add(long long a, long long b) { return a + b; }
long long mul(long long a, long long b) { return a * b; }

struct monkey {
    std::vector<size_t> items{};
    size_t inspected_items{ 0 };

    operation op;
    long long operand;
    int test;
    size_t true_monkey, false_monkey;
};


int main() {
    // Annoying parsing, so cheating.
    monkey monkeys[] = {
        { 
            .items = { 57 },
            .op = &mul, .operand = 13,
            .test = 11,
            .true_monkey = 3, .false_monkey = 2
        },
        { 
            .items = { 58, 93, 88, 81, 72, 73, 65 },
            .op = &add, .operand = 2,
            .test = 7,
            .true_monkey = 6, .false_monkey = 7
        },
        { 
            .items = { 65, 95 },
            .op = &add, .operand = 6,
            .test = 13,
            .true_monkey = 3, .false_monkey = 5
        },{ 
            .items = { 58, 80, 81, 83 },
            .op = &mul, .operand = 0,
            .test = 5,
            .true_monkey = 4, .false_monkey = 5
        },
        { 
            .items = { 58, 89, 90, 96, 55 },
            .op = &add, .operand = 3,
            .test = 3,
            .true_monkey = 1, .false_monkey = 7
        },
        { 
            .items = { 66, 73, 87, 58, 62, 67 },
            .op = &mul, .operand = 7,
            .test = 17,
            .true_monkey = 4, .false_monkey = 1
        },
        { 
            .items = { 85, 55, 89 },
            .op = &add, .operand = 4,
            .test = 2,
            .true_monkey = 2, .false_monkey = 0
        },
        { 
            .items = { 73, 80, 54, 94, 90, 52, 69, 58 },
            .op = &add, .operand = 7,
            .test = 19,
            .true_monkey = 6, .false_monkey = 0
        }
    };
    
    long long module = 1;
    for (auto &monkey : monkeys) {
        module *= monkey.test;
    }

    std::cout << module << std::endl;

    // 10000 turni
    for (int i = 0; i < 10000; i++) {
        for (auto &monkey : monkeys) {
            for (auto item : monkey.items) {
                monkey.inspected_items++;
                auto new_worry_level = monkey.op(item, monkey.operand ? monkey.operand : item) % module;
                if ((new_worry_level % monkey.test) == 0) {
                    monkeys[monkey.true_monkey].items.push_back(new_worry_level);
                } else {
                    monkeys[monkey.false_monkey].items.push_back(new_worry_level);
                }

            }
            monkey.items.clear();
        }
    }

    size_t max1 = 0, max2 = 0;

    for (auto &monkey : monkeys) {
        if (monkey.inspected_items > max1) {
            if (max1 > max2) {
                max2 = max1;
            }
            max1 = monkey.inspected_items;
        } else if (monkey.inspected_items > max2) {
            max2 = monkey.inspected_items;
        }
    }

    std::cout << max1 * max2 << std::endl;
}
