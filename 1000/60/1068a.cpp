#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer m, integer k, integer l)
{
    const integer q = (k + l + m - 1) / m;
    if (q * m > n)
        return no_answer();

    answer(q);
}

int main()
{
    integer n, m, k, l;
    std::cin >> n >> m >> k >> l;

    solve(n, m, k, l);

    return 0;
}
