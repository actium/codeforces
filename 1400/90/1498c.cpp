#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<std::vector<unsigned>> dp(1+k, std::vector<unsigned>(1+n));
    for (unsigned i = 1; i <= k; ++i) {
        unsigned v = 1;
        for (unsigned j = 0; j < n; ++j) {
            dp[i][j] = v;
            v += dp[i-1][n-1-j];
            v %= M;
        }
        dp[i][n] = v;
    }

    answer(dp[k][n]);
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
