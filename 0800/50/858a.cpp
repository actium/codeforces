#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    integer x = 1;
    while (k-- > 0)
        x *= 10;

    answer(x * n / std::gcd(x, n));
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

