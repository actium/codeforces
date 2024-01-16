#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0) >> 1;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b)
{
    const size_t n = s.length();

    std::vector<std::vector<integer>> dp(2, std::vector<integer>(1+n, oo));
    dp[0][0] = b;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0') {
            dp[0][i+1] = std::min(dp[0][i], dp[1][i] + a) + a + b;
            dp[1][i+1] = std::min(dp[0][i] + a, dp[1][i]) + a + 2 * b;
        } else {
            dp[1][i+1] = dp[1][i] + a + 2 * b;
        }
    }

    answer(dp[0][n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);
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
