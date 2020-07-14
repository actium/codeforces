#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned n, unsigned s)
{
    const unsigned k = s % n;

    answer(k <= b && 1ull * a * n + b >= s);
}

void test_case()
{
    unsigned a, b, n, s;
    std::cin >> a >> b >> n >> s;

    solve(a, b, n, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

