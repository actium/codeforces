#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    unsigned p = 0, s = 0;
    for (unsigned i = 0; i <= n; ++i) {
        if (p + 1 <= k - 1 && std::min(p + 1, s) + std::max(p + 1, s) * 2 - 1 <= m)
            ++p;

        if (s + 1 <= n - k && std::min(p, s + 1) + std::max(p, s + 1) * 2 - 1 <= m)
            ++s;
    }

    answer(p + 1 + s);
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
