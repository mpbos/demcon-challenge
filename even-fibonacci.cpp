#include <iostream>

int main() {
    uint sum = 2;
    uint prev_prev_number = 0;
    uint prev_number = 2;
    uint next_even_number = 8;

    while (next_even_number < 4000000) {
        sum += next_even_number;
        prev_prev_number = prev_number;
        prev_number = next_even_number;
        next_even_number = prev_prev_number + 4 * prev_number;
    }

    std::cout << sum;

    return 0;
};
