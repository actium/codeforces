#include <iostream>

using integer = unsigned long long;

constexpr unsigned M = 998244353;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned r, unsigned c)
{
    const integer h = n - r + 1, w = m - c + 1;

    integer k = 1;
    for (integer b = 2, p = 1ull * n * m - h * w; p != 0; p /= 2) {
        if (p % 2 == 1)
            k = k * b % M;

        b = b * b % M;
    }

    answer(k);
}

void test_case()
{
    unsigned n, m, r, c;
    std::cin >> n >> m >> r >> c;

    solve(n, m, r, c);
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
