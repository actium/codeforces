#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(size_t x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t a, size_t b, size_t c, size_t d, size_t k)
{
    const size_t x = (a + c - 1) / c;
    const size_t y = (b + d - 1) / d;

    if (x + y > k)
        answer(-1);
    else
        answer(x, y);
}

void test_case()
{
    size_t a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;

    solve(a, b, c, d, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

