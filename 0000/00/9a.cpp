#include <iostream>
#include <numeric>

void answer(unsigned x, unsigned y)
{
    std::cout << x << '/' << y << '\n';
}

void solve(unsigned y, unsigned w)
{
    const unsigned u = std::max(y, w);

    const unsigned k = 6 - u + 1;
    const unsigned n = 6;

    const unsigned d = std::gcd(k, n);

    answer(k/d, n/d);
}

int main()
{
    unsigned y, w;
    std::cin >> y >> w;

    solve(y, w);

    return 0;
}

