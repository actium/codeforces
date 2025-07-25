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

void solve(integer n, integer l, integer r, integer k)
{
    if (n % 2 == 1)
        return answer(l);

    const integer x = 1ull << 64 - __builtin_clzll(l);
    if (n == 2 || x > r)
        return no_answer();

    answer(k + 2 <= n ? l : x);
}

void test_case()
{
    integer n, l, r, k;
    std::cin >> n >> l >> r >> k;

    solve(n, l, r, k);
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
