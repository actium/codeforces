#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b, const std::string& c)
{
    const size_t n = a.size(), m = b.size();

    std::vector<std::vector<unsigned>> dp(1+n, std::vector<unsigned>(1+m, oo));
    dp[0][0] = 0;
    for (size_t i = 1; i <= n; ++i)
        dp[i][0] = dp[i-1][0] + (c[i-1] != a[i-1]);
    for (size_t j = 1; j <= m; ++j)
        dp[0][j] = dp[0][j-1] + (c[j-1] != b[j-1]);

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j)
            dp[i][j] = std::min(dp[i-1][j] + (c[i+j-1] != a[i-1]), dp[i][j-1] + (c[i+j-1] != b[j-1]));
    }

    answer(dp[n][m]);
}

void test_case()
{
    std::string a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
