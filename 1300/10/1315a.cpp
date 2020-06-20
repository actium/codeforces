#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t x, size_t y)
{
    answer(std::max({ x * b, (a-1 - x) * b, y * a, (b-1 - y) * a }));
}

void test_case()
{
    size_t a, b, x, y;
    std::cin >> a >> b >> x >> y;

    solve(a, b, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

