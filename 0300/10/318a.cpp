#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    const integer m = (n + 1) / 2;

    answer(k <= m ? 2 * (k - 1) + 1 : 2 * (k - m));
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

