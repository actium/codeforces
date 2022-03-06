#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer s)
{
    answer(s / (n * n));
}

void test_case()
{
    integer n, s;
    std::cin >> n >> s;

    solve(n, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
