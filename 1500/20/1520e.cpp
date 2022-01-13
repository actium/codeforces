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
    if (n < 3)
        return answer(0);

    std::vector<integer> p(n), dp(n), r(n), dr(n);
    for (size_t i = 1, j = n-2; i < n; ++i, --j) {
        p[i] = p[i-1] + (s[i-1] == '*');
        r[j] = r[j+1] + (s[j+1] == '*');

        if (i > 1) {
            dp[i] = dp[i-1] + (s[i-1] == '.') * p[i];
            dr[j] = dr[j+1] + (s[j+1] == '.') * r[j];
        }
    }

    integer k = ~0ull;
    for (size_t i = 0; i < n; ++i) {
        integer d = dp[i] + dr[i];
        if (s[i] == '.')
            d += std::min(p[i], r[i]);

        k = std::min(k, d);
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
