#include <iostream>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(unsigned l, unsigned d, unsigned v, unsigned g, unsigned r)
{
    const unsigned p = g + r, q = d % (p * v), e = q < g * v ? 0 : p * v - q;

    answer(double(l + e) / v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned l, d, v, g, r;
    std::cin >> l >> d >> v >> g >> r;

    solve(l, d, v, g, r);

    return 0;
}
