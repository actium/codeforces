#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    const unsigned d = a < b ? b - a : a - b;
    const unsigned k = d / 2;

    size_t x = k * (k + 1);
    if (d % 2 == 1)
        x += d / 2 + 1;

    answer(x);
}

int main()
{
    unsigned a;
    std::cin >> a;

    unsigned b;
    std::cin >> b;

    solve(a, b);

    return 0;
}

