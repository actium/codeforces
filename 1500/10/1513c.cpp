#include <iostream>

constexpr unsigned M = 1000000007;

unsigned c[1 + 200010] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

void initialize()
{
    for (unsigned i = 10; i <= 200010; ++i)
        c[i] = (c[i-9] + c[i-10]) % M;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    unsigned f[10] = {};
    while (n != 0) {
        ++f[n % 10];
        n /= 10;
    }

    unsigned k = 0;
    for (unsigned i = 0; i <= 9; ++i) {
        k += 1ull * f[i] * c[m + i] % M;
        k %= M;
    }

    answer(k);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
