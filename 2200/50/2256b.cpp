#include <array>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::array<unsigned, 4> dp = {
        (s[0] == '0' || s[0] == '?') && (s[1] == '0' || s[1] == '?'),
        (s[0] == '0' || s[0] == '?') && (s[1] == '1' || s[1] == '?'),
        (s[0] == '1' || s[0] == '?') && (s[1] == '0' || s[1] == '?'),
        (s[0] == '1' || s[0] == '?') && (s[1] == '1' || s[1] == '?'),
    };
    for (size_t i = 2; i < n; ++i) {
        switch (s[i]) {
            case '0':
                dp = { dp[2], 0, dp[3], 0 };
                break;
            case '1':
                dp = { 0, dp[0], 0, dp[1] };
                break;
            default:
                dp = { dp[2], dp[0], dp[3], dp[1] };
                break;
        }
    }

    answer(dp[0] + dp[1] + dp[2] + dp[3]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

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
