#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned l, unsigned r, unsigned d, unsigned u)
{
    answer(l == r && r == d && d == u);
}

void test_case()
{
    unsigned l, r, d, u;
    std::cin >> l >> r >> d >> u;

    solve(l, r, d, u);
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
