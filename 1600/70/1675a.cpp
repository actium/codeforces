#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned x, unsigned y)
{
    x -= std::min(x, a);
    y -= std::min(y, b);

    answer(x + y <= c);
}

void test_case()
{
    unsigned a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;

    solve(a, b, c, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
