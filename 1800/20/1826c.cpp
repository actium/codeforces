#include <iostream>
#include <numeric>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned m)
{
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0 && i <= m)
            return answer(false);
    }

    answer(n == 1 || n > m);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
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
