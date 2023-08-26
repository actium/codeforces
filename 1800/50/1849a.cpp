#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned b, unsigned c, unsigned h)
{
    answer(std::min(b - 1, c + h) * 2 + 1);
}

void test_case()
{
    unsigned b, c, h;
    std::cin >> b >> c >> h;

    solve(b, c, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}