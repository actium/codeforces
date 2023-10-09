#include <iostream>
#include <vector>

void answer(unsigned u, const std::vector<std::vector<unsigned>>& v)
{
    std::cout << u << '\n';

    for (const std::vector<unsigned>& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n, size_t m)
{
    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (m == 1 || i % (m - 1) == 0)
                a[i][j] = j;
            else
                a[i][j] = (a[i-1][j] + 1) % m;
        }
    }

    answer(m > 1 ? std::min(n + 1, m) : 0, a);
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
