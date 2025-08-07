#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer count(integer n)
{
    constexpr unsigned t[4] = { 2, 3, 5, 7 };

    integer q = 0;
    for (unsigned i = 0; i < 16; ++i) {
        unsigned m = 1;
        for (unsigned x = i; x != 0; x &= x - 1)
            m *= t[__builtin_ctz(x)];

        if (__builtin_popcount(i) % 2 == 0)
            q += n / m;
        else
            q -= n / m;
    }
    return q;
}

void solve(integer l, integer r)
{
    answer(count(r) - count(l-1));
}

void test_case()
{
    integer l, r;
    std::cin >> l >> r;

    solve(l, r);
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
