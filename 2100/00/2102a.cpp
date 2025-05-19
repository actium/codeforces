#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned m, unsigned p, unsigned q)
{
    const unsigned c = n / p, r = n % p;

    answer(r != 0 || c * q == m);
}

void test_case()
{
    unsigned n, m, p, q;
    std::cin >> n >> m >> p >> q;

    solve(n, m, p, q);
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
