#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer m, integer a)
{
    const integer hc = (n + a - 1) / a;
    const integer vc = (m + a - 1) / a;

    answer(hc * vc);
}

int main()
{
    integer n, m, a;
    std::cin >> n >> m >> a;

    solve(n, m, a);

    return 0;
}

