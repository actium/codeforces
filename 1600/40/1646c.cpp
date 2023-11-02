#include <iostream>

using integer = unsigned long long;

constexpr integer t[] = {
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
};

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    unsigned k = ~0u;
    for (unsigned i = 0; i < 1 << 12; ++i) {
        integer s = 0;
        for (unsigned x = i; x != 0; x &= x - 1)
            s += t[__builtin_ctz(x)];

        if (s <= n)
            k = std::min<unsigned>(k, __builtin_popcount(i) + __builtin_popcountll(n - s));
    }

    answer(k);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
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
