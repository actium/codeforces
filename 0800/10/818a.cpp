#include <iostream>

using integer = long long;

void answer(integer x, integer y, integer z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(integer n, integer k)
{
    const integer x = (n / 2) / (1 + k);

    answer(x, x * k, n - x - x * k);
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

