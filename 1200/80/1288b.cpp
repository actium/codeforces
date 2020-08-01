#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    integer k = 0;
    for (integer x = 9; x <= b; x = (x * 10) + 9)
        k += a;

    answer(k);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

