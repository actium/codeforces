#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned x, unsigned y)
{
    answer(a < std::min(x, y) || a > std::max(x, y));
}

void test_case()
{
    unsigned a, x, y;
    std::cin >> a >> x >> y;

    solve(a, x, y);
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
