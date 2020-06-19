#include <iostream>

void solve(size_t n)
{
    std::cout << (n * n + 1) / 2 << '\n';

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cout << ((i+j) % 2 == 0 ? 'C' : '.');

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

