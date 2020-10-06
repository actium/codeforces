#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(integer n, integer m)
{
    while ((n >= 2 * m && m > 0) || (m >= 2 * n && n > 0)) {
        if (n >= 2 * m)
            n %= 2 * m;
        else
            m %= 2 * n;
    }

    answer(n, m);
}

int main()
{
    integer n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

