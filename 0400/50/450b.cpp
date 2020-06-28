#include <iostream>

constexpr long mod = 1000000007;

void answer(long v)
{
    std::cout << v << '\n';
}

void solve(long x, long y, size_t n)
{
    const long f[6] = { x, y, y - x, -x, -y, x - y };

    long z = f[(n - 1) % 6];
    while (z < 0)
        z += mod;

    answer(z % mod);
}

int main()
{
    long x, y;
    std::cin >> x >> y;

    size_t n;
    std::cin >> n;

    solve(x, y, n);

    return 0;
}

