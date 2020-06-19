#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b)
{
    size_t delta = a < b ? b - a : a - b;

    const size_t c5 = delta / 5;
    delta -= c5 * 5;

    const size_t c2 = delta / 2;
    delta -= c2 * 2;

    const size_t c1 = delta;
    answer(c5 + c2 + c1);
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

