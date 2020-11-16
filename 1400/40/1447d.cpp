#include <iostream>
#include <string>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length(), m = b.length();

    int x = 0;

    std::vector<std::vector<int>> dp(1+n, std::vector<int>(1+m));
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) - 1;
            dp[i][j] = std::max(dp[i][j], 0);

            if (a[i-1] == b[j-1])
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-1] + 2);

            x = std::max(x, dp[i][j]);
        }
    }

    answer(x);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

