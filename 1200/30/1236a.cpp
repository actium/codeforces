#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t c)
{
    const size_t x1 = std::min(a, b / 2);
    const size_t y1 = std::min(b - 2 * x1, c / 2);

    const size_t y2 = std::min(b, c / 2);
    const size_t x2 = std::min(a, (b - y2) / 2);

    answer(3 * std::max(x1 + y1, x2 + y2));
}

void test_case()
{
    size_t a, b, c;
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

