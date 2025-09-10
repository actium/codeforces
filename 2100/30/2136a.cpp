#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    c -= a;
    d -= b;

    if (a > b)
        std::swap(a, b);

    if (c > d)
        std::swap(c, d);

    answer(b <= 2 * a + 2 && d <= 2 * c + 2);
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
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
