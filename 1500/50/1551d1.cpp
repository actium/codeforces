#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    const unsigned q = m / 2;

    if (n % 2 == 1) {
        answer(k >= q && (k - q) % 2 == 0);
    } else {
        answer(k <= q * n && k % 2 == 0);
    }
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
