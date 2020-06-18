#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b)
{
    const size_t x = std::min(a, b);
    const size_t y = std::max(a, b);
    const size_t z = std::max(2 * x, y);

    answer(z * z);
}

void test_case()
{
    size_t a, b;
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

