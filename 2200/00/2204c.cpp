#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x, integer y, integer z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

integer compute(integer m, unsigned a, unsigned b, unsigned c)
{
    const integer pab = std::lcm<integer>(a, b);
    const integer pac = std::lcm<integer>(a, c);

    const integer k1 = m / a;
    const integer k2 = m / pab + m / pac;
    const integer k3 = m / std::lcm(pab, pac);

    return 6 * k1 - 3 * k2 + 2 * k3;
}

void solve(unsigned a, unsigned b, unsigned c, integer m)
{
    answer(compute(m, a, b, c), compute(m, b, c, a), compute(m, c, a, b));
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    integer m;
    std::cin >> m;

    solve(a, b, c, m);
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
