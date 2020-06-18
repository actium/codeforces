#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k, unsigned l, unsigned c, unsigned d, unsigned p, unsigned nl, unsigned np)
{
    const unsigned x1 = k * l / nl;
    const unsigned x2 = c * d;
    const unsigned x3 = p / np;

    answer(std::min({ x1, x2, x3 }) / n);
}

int main()
{
    unsigned n, k, l, c, d, p, nl, np;
    std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    solve(n, k, l, c, d, p, nl, np);

    return 0;
}

