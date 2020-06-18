#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t m)
{
    answer(n == 1 || m == 1 || n == 2 && m == 2);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t--)
        test_case();

    return 0;
}

