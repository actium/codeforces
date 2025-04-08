#include <array>
#include <iostream>

constexpr unsigned M = 1'000'000'007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned n)
{
    if (n == 1)
        return 2;

    std::array<unsigned, 4> c = { 1, 1, 1, 1 };
    for (unsigned i = 3; i <= n; ++i)
        c = { c[2], (c[0] + c[2]) % M, (c[1] + c[3]) % M, c[1] };

    unsigned k = 0;
    for (const unsigned x : c)
        k = (k + x) % M;

    return k;
}

void solve(unsigned n, unsigned m)
{
    answer((count(n) + count(m) - 2) % M);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
