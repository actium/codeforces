#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k)
{
    constexpr unsigned M = 1000000007;

    unsigned x = 6;
    for (unsigned long long b = 4, p = (1ull << k) - 2; p != 0; p /= 2) {
        if (p & 1)
            x = x * b % M;

        b = b * b % M;
    }

    answer(x);
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}
