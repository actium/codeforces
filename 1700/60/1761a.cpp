#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    answer(a == n && b == n || a + b + 1 < n);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
