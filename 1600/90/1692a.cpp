#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    answer((b > a) + (c > a) + (d > a));
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
