#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y, unsigned a)
{
    answer(x <= a % (x + y));
}

void test_case()
{
    unsigned x, y, a;
    std::cin >> x >> y >> a;

    solve(x, y, a);
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
