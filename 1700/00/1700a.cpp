#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    integer c = 0;

    for (unsigned i = 1; i < m; ++i)
        c += i;

    for (unsigned i = 1; i <= n; ++i)
        c += i * m;

    answer(c);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
