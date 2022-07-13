#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned m)
{
    unsigned x = 1;
    while (x * 10 <= m)
        x *= 10;

    answer(m - x);
}

void test_case()
{
    unsigned m;
    std::cin >> m;

    solve(m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
