#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned n)
{
    double x = 0;
    for (unsigned i = n; i > 0; --i)
        x += 1.0 / i;

    answer(x);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

