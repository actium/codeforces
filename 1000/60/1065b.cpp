#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

using integer = unsigned long long;

void solve(integer n, integer m)
{
    integer x = 0;
    while (x * (x - 1) / 2 < m)
        ++x;

    answer(2 * m < n ? n - 2 * m : 0, n - x);
}

int main()
{
    integer n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

