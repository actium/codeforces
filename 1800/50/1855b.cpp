#include <iostream>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    unsigned x = 2;
    while (n % x == 0)
        ++x;

    answer(x - 1);
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
