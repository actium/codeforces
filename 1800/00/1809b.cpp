#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer x)
{
    integer p = sqrt(x);
    while (p * p < x)
        ++p;

    answer(p - 1);
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
