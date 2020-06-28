#include <iostream>

void solve(size_t n)
{
    const size_t k = n * n;                 // number of candy bags

    const size_t s = k * (k + 1) / 2;       // total number of candies
    const size_t m = s / n;                 // how many candies to give to a brother

    for (size_t i = 0; i < n; ++i) {
        const char* separator = "";
        for (size_t j = 0; j < n / 2; ++j) {
            std::cout << separator << k - n * i / 2 - j << ' ' << 1 + n * i / 2 + j;
            separator = " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

