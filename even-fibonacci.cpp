#include <iostream>

#include <chrono>

// Code copied from https://stackoverflow.com/questions/11085393/matlab-tic-toc-equivalent-in-c
void tic(int mode=0) {
    static std::chrono::_V2::system_clock::time_point t_start;

    if (mode==0)
        t_start = std::chrono::high_resolution_clock::now();
    else {
        auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "Elapsed time is " << (t_end-t_start).count()*1E-9 << " seconds\n";
    }
}
void toc() { tic(1); }

using namespace std;

int main()
{
    tic();

    int sum = 2;
    int prev_prev_number = 1;
    int prev_number = 2;
    int next_number = 3;

    while (next_number < 4000000)
    {
        if (next_number % 2 == 0)
            sum += next_number;
        prev_prev_number = prev_number;
        prev_number = next_number;
        next_number = prev_prev_number + prev_number;
    }

    cout << sum;

    toc();

    return 0;
};
