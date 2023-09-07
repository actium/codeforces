#include <iostream>

void solve(size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i % 2 == 0) {
                std::cout << 1 + (n / 2 + i / 2) * m + j << ' ';
            } else {
                std::cout << 1 + i / 2 * m + j << ' ';
            }
        }
        std::cout << '\n';
    }
}

void test_case()
{
    size_t n, m;
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
