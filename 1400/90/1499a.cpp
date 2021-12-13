#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(unsigned k1, unsigned k2, unsigned x)
{
    const auto c = std::min(k1, k2);
    const auto d = std::max(k1, k2) - c;

    return c + d / 2 >= x;
}

void solve(unsigned n, unsigned k1, unsigned k2, unsigned w, unsigned b)
{
    answer(check(k1, k2, w) && check(n - k1, n - k2, b));
}

void test_case()
{
    unsigned n, k1, k2;
    std::cin >> n >> k1 >> k2;

    unsigned w, b;
    std::cin >> w >> b;

    solve(n, k1, k2, w, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
