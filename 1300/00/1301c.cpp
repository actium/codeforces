#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer turan(integer n, unsigned r)
{
    const integer s = n % r;

    return (n * n - s - (n * n - s * s) / r) / 2;
}

void solve(unsigned n, unsigned m)
{
    answer(turan(n + 1, m + 1));
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
