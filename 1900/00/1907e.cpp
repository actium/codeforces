#include <iostream>

using integer = unsigned long long;

integer count(unsigned n)
{
    constexpr unsigned t[10] = { 1, 3, 6, 10, 15, 21, 28, 36, 45, 55 };

    return n < 10 ? t[n] : count(n / 10) * t[n % 10];
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(count(n));
}

void test_case()
{
    unsigned n;
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
