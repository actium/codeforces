#include <iostream>

#include <cmath>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(unsigned m, unsigned n)
{
    double v = 0;
    for (unsigned i = 1; i <= m; ++i)
        v += i * (pow(double(i) / m, n) - pow(double(i - 1) / m, n));

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned m, n;
    std::cin >> m >> n;

    solve(m, n);

    return 0;
}
