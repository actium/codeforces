#include <iostream>

unsigned msb(unsigned x)
{
    return 1 << __builtin_clz(1) - __builtin_clz(x);
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned l, unsigned r)
{
    const unsigned x = l | msb(l ^ r) - 1;

    answer(x, x + 1, x == l ? r : l);
}

void test_case()
{
    unsigned l, r;
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
