#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(int a, int b, int c, int r)
{
    if (a > b)
        std::swap(a, b);

    const int x1 = c - r;
    const int x2 = c + r;

    unsigned d = 0;
    if (a < x1)
        d += std::min(x1, b) - a;
    if (b > x2)
        d += b - std::max(x2, a);

    answer(d);
}

void test_case()
{
    int a, b, c, r;
    std::cin >> a >> b >> c >> r;

    solve(a, b, c, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

