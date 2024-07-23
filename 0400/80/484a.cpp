#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer lb, integer ub)
{
    integer x = 1ull << 60;
    while (x != 0 && (lb & x) == (ub & x))
        x >>= 1;

    if (x != 0)
        lb |= x - 1;

    answer(__builtin_popcountll(lb) < __builtin_popcountll(ub) ? ub : lb);
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
