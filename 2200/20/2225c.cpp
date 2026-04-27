#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string (& s)[2])
{
    const size_t n = s[0].size();

    std::vector<unsigned> dp(1+n, oo);
    dp[0] = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i != 0)
            dp[i+1] = dp[i-1] + (s[0][i-1] != s[0][i]) + (s[1][i-1] != s[1][i]);

        dp[i+1] = std::min(dp[i+1], dp[i] + (s[0][i] != s[1][i]));
    }

    answer(dp[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s[2];
    std::cin >> s[0] >> s[1];

    solve(s);
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
