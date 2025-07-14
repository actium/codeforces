#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned x, unsigned y)
{
    if (a > b)
        return (a ^ 1) == b ? answer(y) : no_answer();

    unsigned c = 0;
    while (a < b)
        c += (a++ & 1) == 1 ? x : std::min(x, y);

    answer(c);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    unsigned x, y;
    std::cin >> x >> y;

    solve(a, b, x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
