#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    const auto q = n * (n - 1ull) / 2;
    if (m < n-1 || m > q)
        return answer(false);

    const auto d = std::min<unsigned>(n-1, (q == m ? 1 : 2));
    answer(d + 1 < k);
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
