#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer(a + (a != 0) * b * 2 + 1);
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

