#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    while (n != 0 && n % 2 == 0)
        n /= 2;

    unsigned x = 0;
    for (unsigned r = n; r != 0; r >>= 1)
        x = (x << 1) | (r & 1);

    answer((n ^ x) == 0 && __builtin_popcount(n & x) % 2 == 0);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
