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

void solve(integer n, integer x)
{
    if (n == x)
        return answer(n);

    if (x == 0)
        return answer(1ull << __builtin_clzll(1) - __builtin_clzll(n) + 1);

    const unsigned k = __builtin_ctzll(x);
    if (k == 0)
        return n == x ? answer(n) : no_answer();

    const integer s = 1ull << k, m = n & ~(s - 1);
    if ((m ^ x) != 0 || (n & s >> 1) != 0)
        return no_answer();

    integer t = s >> 1;
    while (t != 0 && (n & t >> 1) == 0)
        t >>= 1;

    answer(n + t - (n & (t - 1)));
}

void test_case()
{
    integer n, x;
    std::cin >> n >> x;

    solve(n, x);
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
