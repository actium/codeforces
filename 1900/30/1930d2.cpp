#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    integer t = 0;

    std::vector<integer> dp(n + 3);
    for (size_t i = n-1; ~i != 0; --i) {
        dp[i] = (s[i] == '0' ? dp[i+1] : dp[i+3] + n - i);
        t += dp[i];
    }

    answer(t);
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
