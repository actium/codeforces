#include <iostream>

constexpr unsigned M = 1e9 + 7;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    // n! - 2^(n-1)

    unsigned long long x = 1;
    for (unsigned i = 2; i <= n; ++i)
        x = (x * i) % M;

    unsigned long long y = 1;
    for (unsigned i = 2; i <= n; ++i)
        y = (y * 2) % M;

    answer((x - y + M) % M);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

