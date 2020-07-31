#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    const integer m = (sqrt(8 * n - 7) - 1) / 2;
    const integer a = n - m * (m + 1) / 2;

    answer(a);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

