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

void solve(integer n, integer m, integer k)
{
    if (n > m)
        std::swap(n, m);

    if (k < m)
        return no_answer();

    const integer d = (n + m) % 2;

    answer((k - n) % 2 == 0 ? k - d : k - 2 + d);
}

void test_case()
{
    integer n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
