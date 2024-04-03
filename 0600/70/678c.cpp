#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned p, unsigned q)
{
    const integer ka = n / a, kb = n / b, kc = n / std::lcm<integer>(a, b);
    answer(ka * p + kb * q - kc * std::min(p, q));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, a, b, p, q;
    std::cin >> n >> a >> b >> p >> q;

    solve(n, a, b, p, q);

    return 0;
}
