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

void solve(integer x, integer y)
{
    if (x < y)
        std::swap(x, y);

    const integer k = (1ull << __builtin_clzll(1) - __builtin_clzll(x) + 1) - x;
    x += k, y += k;
    if ((x + y) == (x ^ y))
        return answer(k);

    no_answer();
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
