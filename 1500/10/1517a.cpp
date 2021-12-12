#include <iostream>

using integer = unsigned long long;

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    if (n % 2050 != 0)
        return no_answer();

    unsigned k = 0;
    for (integer x = n / 2050; x != 0; x /= 10)
        k += x % 10;

    answer(k);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
