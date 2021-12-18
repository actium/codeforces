#include <iostream>

using point_t = std::pair<unsigned, unsigned>;

void answer(const point_t& x, const point_t& y)
{
    std::cout << x.first << ' ' << x.second << ' ';
    std::cout << y.first << ' ' << y.second << '\n';
}

void solve(unsigned n, unsigned m, const point_t& a)
{
    answer({ 1, 1 }, { n, m });
}

void test_case()
{
    unsigned n, m, i, j;
    std::cin >> n >> m >> i >> j;

    solve(n, m, { i, j });
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
