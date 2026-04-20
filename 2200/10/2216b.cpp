#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned t, unsigned h, unsigned u)
{
    integer n = 2 * integer(t + h + u) + h;
    n += (t > 2 * h + u ? 1 : u - std::min(t, u));

    answer(n);
}

void test_case()
{
    unsigned t, h, u;
    std::cin >> t >> h >> u;

    solve(t, h, u);
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
