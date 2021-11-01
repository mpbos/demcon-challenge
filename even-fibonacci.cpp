#include <iostream>

#include <chrono>

// Code copied from https://stackoverflow.com/questions/11085393/matlab-tic-toc-equivalent-in-c
void tic(int mode = 0) {
    static std::chrono::_V2::system_clock::time_point t_start;

    if (mode == 0)
        t_start = std::chrono::high_resolution_clock::now();
    else {
        auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "Elapsed time is " << (t_end - t_start).count() * 1E-9 << " seconds\n";
    }
}

void toc() { tic(1); }

using namespace std;

int main() {
    tic();

    for (int i = 0; i < 100000; ++i) {

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

        cout << sum;

    }

    toc();

    return 0;
};
