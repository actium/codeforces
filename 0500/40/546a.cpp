#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned n, unsigned w)
{
    const unsigned sum_i = w * (w + 1) / 2;
    const unsigned cost = sum_i * k;

    answer(cost > n ? cost - n : 0);
}

int main()
{
    unsigned k, n, w;
    std::cin >> k >> n >> w;

    solve(k, n, w);

    return 0;
}

