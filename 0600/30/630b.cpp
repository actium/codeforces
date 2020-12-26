#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(long double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned n, integer t)
{
    answer(n * pow(1.000000011, t));
}

int main()
{
    unsigned n;
    std::cin >> n;

    integer t;
    std::cin >> t;

    solve(n, t);

    return 0;
}

