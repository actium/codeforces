#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned m, unsigned r, unsigned c, unsigned d)
{
    if ((1 + d < r && c + d < m) || (1 + d < c && r + d < n))
        return answer(n - 1 + m - 1);

    no_answer();
}

void test_case()
{
    unsigned n, m, r, c, d;
    std::cin >> n >> m >> r >> c >> d;

    solve(n, m, r, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
