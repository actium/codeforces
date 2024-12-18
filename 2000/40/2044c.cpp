#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned m, unsigned a, unsigned b, unsigned c)
{
    const unsigned d = m - std::min(m, a), e = m - std::min(m, b);

    answer(std::min(m, a) + std::min(m, b) + std::min(d + e, c));
}

void test_case()
{
    unsigned m, a, b, c;
    std::cin >> m >> a >> b >> c;

    solve(m, a, b, c);
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
