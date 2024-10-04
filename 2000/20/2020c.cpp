#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer b, integer c, integer d)
{
    // b c d    a
    // ----------
    // 0 0 0    0
    // 0 0 1    1
    // 0 1 0    0
    // 0 1 1    x
    // 1 0 0    x
    // 1 0 1    0
    // 1 1 0    1
    // 1 1 1    0

    integer a = 0;
    for (unsigned i = 0; i < 60; ++i) {
        const unsigned x = (b >> i & 1) * 4 + (c >> i & 1) * 2 + (d >> i & 1);
        if (x == 3 || x == 4)
            return no_answer();

        a |= integer(x == 1 || x == 6) << i;
    }

    answer(a);
}

void test_case()
{
    integer b, c, d;
    std::cin >> b >> c >> d;

    solve(b, c, d);
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
