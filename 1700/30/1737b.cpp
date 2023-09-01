#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer lb, integer ub)
{
    integer lx = sqrt(lb) - 1;
    while (lx * (lx + 2) < lb)
        ++lx;

    integer ux = sqrt(ub) - 1;
    while (ux * (ux + 2) < ub)
        ++ux;

    integer k = (ux - lx + 1) * 3;

    k -= (lx * lx < lb);
    k -= (lx * (lx + 1) < lb);

    k -= (ux * ux > ub);
    k -= (ux * (ux + 1) > ub);
    k -= (ux * (ux + 2) > ub);

    answer(k);
}

void test_case()
{
    integer lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
