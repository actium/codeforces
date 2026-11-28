#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned a, unsigned b)
{
    answer(l / std::lcm(std::gcd(a, l), std::gcd(b, l)));
}

void test_case()
{
    unsigned l, a, b;
    std::cin >> l >> a >> b;

    solve(l, a, b);
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
