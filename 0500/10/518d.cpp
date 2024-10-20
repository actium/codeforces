#include <iomanip>
#include <iostream>
#include <vector>

void answer(double x)
{
    std::cout << std::fixed << std::setprecision(10) << x << '\n';
}

void solve(unsigned n, double p, unsigned t)
{
    std::vector<std::vector<double>> dp(1+t, std::vector<double>(1+n));
    dp[0][0] = 1;
    for (unsigned i = 1; i <= t; ++i) {
        dp[i][0] = dp[i-1][0] * (1 - p);

        for (unsigned j = 1; j < n; ++j)
            dp[i][j] = dp[i-1][j] * (1 - p) + dp[i-1][j-1] * p;

        dp[i][n] += dp[i-1][n] + dp[i-1][n-1] * p;
    }

    double x = 0;
    for (unsigned i = 1; i <= n; ++i)
        x += i * dp[t][i];

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    double p;
    std::cin >> p;

    unsigned t;
    std::cin >> t;

    solve(n, p, t);

    return 0;
}
