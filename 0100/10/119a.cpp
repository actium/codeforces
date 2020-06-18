#include <iostream>
#include <numeric>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned n)
{
    size_t i = 0;
    for (unsigned d; d = std::gcd(i % 2 == 0 ? a : b, n), d <= n; n -= d)
        ++i;

    answer((i + 1) % 2);
}

int main()
{
    unsigned a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);

    return 0;
}

