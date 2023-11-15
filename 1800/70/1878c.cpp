#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, integer k, integer x)
{
    const integer lb = k * (k + 1) / 2, ub = k * (2 * n - k + 1) / 2;

    answer(lb <= x && ub >= x);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    integer x;
    std::cin >> x;

    solve(n, k, x);
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
