#include <iostream>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    const unsigned u = b * (b - 1ull) / 2 % M, v = a * (a + 1ull) / 2 % M, w = (1ull * v * b + a) % M;

    answer(1ull * w * u % M);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
