#include <iostream>

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m, int l)
{
    const unsigned d = std::min<unsigned>(std::abs(l), n - m);
    answer(l + d, l + d + m);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    int l, r;
    std::cin >> l >> r;

    solve(n, m, l);
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
