#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned p)
{
    answer(2, p - p % 2);
}

void test_case()
{
    unsigned p;
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
