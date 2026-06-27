#include <iostream>

using integer = unsigned long long;

constexpr unsigned M = 998244353;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer x)
{
    const auto p = (x + 4) / 4 % M, q = ((n + 5) / 4 - p) % M;
    const auto s = (x + 2) / 4 % M, t = ((n + 3) / 4 - s) % M;

    answer((p * q + s * t) % M);
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
