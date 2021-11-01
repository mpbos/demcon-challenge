#include <iostream>

int main() {
    // To compute the sum of even fibonacci numbers, we use a mathematical method to compute the even fibonacci numbers
    // instead of using if statements. It should be noted that the fibonacci-sequence has an ordering of
    // uneven -> even -> uneven -> uneven -> even -> uneven ...,
    // so that every third entry is an even number.
    // Using the equation for fibonacci numbers, c = b + a (where c follows b, and b follows a in the sequence), we can
    // obtain an equation which can skip a few computations.
    // Say we have a sequence: a -> B -> c -> d -> E -> f -> g -> H, where capitals B, E and H are even, and lower-case
    // a, c, d, f and g are uneven. We can compute H as:
    // H = g + f
    //   = 2f + E          (using g = f + E)
    //   = 3E + 2d         (using f = E + d)
    //   = 3E + d + c + B  (using d = c + B)
    //   = 4E + B          (using E = d + c)
    // Using this equation, there is no need anymore to compute any uneven fibonacci number.

    // The sum of all even fibonacci numbers so far (we need to take into account the starting number 2, which is not
    // taking into account in the loop)
    uint sum = 2;
    // The number before the previous number, which is 0 initially
    uint prev_prev_number = 0;
    // The number before the number which we are currently computing, which is 2 initially (the first even fibonacci
    // number)
    uint prev_number = 2;
    // The next even fibonacci number that will get computed in the loop, which is 8 initially (the second even
    // fibonacci number)
    uint next_even_number = 8;

    // We loop until the next fibonacci number is larger than or equal to 4million (using < or <= wouldn't matter, since
    // 4million is not a fibonacci number)
    while (next_even_number < 4000000) {
        // Increase the total sum
        sum += next_even_number;
        // Transfer the values back to the previous place
        prev_prev_number = prev_number;
        prev_number = next_even_number;
        // Compute the next even fibonacci number using the equation above (H = 4E + B)
        next_even_number = prev_prev_number + 4 * prev_number;
    }

    // Output the result
    std::cout << sum;

    return 0;
};
