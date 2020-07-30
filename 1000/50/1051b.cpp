#include <iostream>

using integer = unsigned long long;

void solve(integer l, integer r)
{
    std::cout << "YES" << '\n';

    for (integer i = l; i < r; i += 2)
        std::cout << i << ' ' << i + 1 << '\n';
}

int main()
{
    integer l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}

