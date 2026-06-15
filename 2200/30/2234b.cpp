#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n)
{
    if (n == 10)
        return no_answer();

    unsigned r = n % 12;
    if (r == 10)
        r += 12;

    answer(r, n - r);
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
