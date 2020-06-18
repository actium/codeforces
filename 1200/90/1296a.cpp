#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const size_t f[2])
{
    answer(f[1] > 0 && (f[1] % 2 != 0 || f[0] > 0));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    size_t f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        ++f[a % 2];
    }

    solve(f);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

