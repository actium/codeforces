#include <iostream>
#include <numeric>

using integer = long long;

integer sum(unsigned a, unsigned n)
{
    return n * (2ull * a + n - 1) / 2;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    const unsigned d = n / std::lcm<integer>(x, y), kx = n / x - d, ky = n / y - d;

    answer(sum(n - kx + 1, kx) - sum(1, ky));
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
