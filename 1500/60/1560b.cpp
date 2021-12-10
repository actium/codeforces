#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    if (a > b)
        std::swap(a, b);

    if (2 * a > b)
        return no_answer();

    const unsigned d = b - a;
    if (c > 2 * d)
        return no_answer();

    answer(c > d ? c - d : c + d);
}

void test_case()
{
    unsigned a, b, c;
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
