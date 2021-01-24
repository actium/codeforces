#include <iostream>

void solve(unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i) {
        const unsigned k = i % m;
        if (k % 2 != m % 2) {
            std::cout << (m + k + 1) / 2 << '\n';
        } else {
            std::cout << (m - k) / 2 << '\n';
        }
    }
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

