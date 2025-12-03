#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    const auto v = [n](unsigned i, unsigned j) {
        return i >= 1 && i <= n && j >= 1 && j <= n ? (i - 1) * n + j : 0;
    };

    unsigned s = 0;
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= n; ++j)
            s = std::max(s, v(i-1, j) + v(i, j-1) + v(i, j) + v(i, j+1) + v(i+1, j));
    }

    answer(s);
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
