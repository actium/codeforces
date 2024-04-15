#include <array>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::array<unsigned, 6> dp = {};
    for (const char c : s) {
        dp = {
            c == '0' ? dp[1] + 1 : dp[0],
            c == '1' ? dp[0] + 1 : dp[1],
            c == '1' ? std::max(dp[1], dp[3]) + 1 : std::max(dp[0], dp[2]),
            c == '0' ? std::max(dp[0], dp[2]) + 1 : std::max(dp[1], dp[3]),
            c == '0' ? std::max(dp[3], dp[5]) + 1 : std::max(dp[2], dp[4]),
            c == '1' ? std::max(dp[2], dp[4]) + 1 : std::max(dp[3], dp[5]),
        };
    }

    answer(std::max(dp[4], dp[5]));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
