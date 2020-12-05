#include <iostream>

#define _GNU_SOURCE
#include <cmath>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned n, unsigned r)
{
    const double x = std::sin(M_PI / n);
    const double ratio = x / (x + 1);

    answer(ratio * r / (1 - 2 * ratio));
}

int main()
{
    unsigned n, r;
    std::cin >> n >> r;

    solve(n, r);

    return 0;
}

