#include <iostream>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (k == n * n - 1)
        return no_answer();

    std::vector<std::string> g(n, std::string(n, '?'));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            g[i][j] = (i * n + j < k ? 'U' : i < n-1 ? 'D' : 'R');
    }
    g[n-1][n-1] = 'L';

    answer(g);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
