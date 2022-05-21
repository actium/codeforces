#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y, integer z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    answer(a + b + c, b + c, c);
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

