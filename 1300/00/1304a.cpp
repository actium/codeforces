#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(size_t x, size_t y, size_t a, size_t b)
{
    const size_t d = y - x;
    const size_t p = a + b;
    answer(d % p == 0 ? d / p : -1);
}

void test_case()
{
    size_t x, y, a, b;
    std::cin >> x >> y >> a >> b;

    solve(x, y, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

