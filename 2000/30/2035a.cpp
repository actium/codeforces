#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned r, unsigned c)
{
    answer((n - r) * (2 * m - 1ull) + (m - c));
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
