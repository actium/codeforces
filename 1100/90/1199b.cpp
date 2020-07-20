#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned h, unsigned l)
{
    answer((1ull * l * l - 1ull * h * h) / 2.0 / h);
}

int main()
{
    unsigned h, l;
    std::cin >> h >> l;

    solve(h, l);

    return 0;
}

