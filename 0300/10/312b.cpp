#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const double x = double(a) / b, y = double(c) / d, z = (1 - x) * (1 - y);

    answer(x / (1 - z));
}

int main()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);

    return 0;
}

