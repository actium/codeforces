#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& s, const std::vector<unsigned>& c)
{
    const size_t n = s.size();

    std::vector<std::string> t(n);
    for (size_t i = 0; i < n; ++i)
        t[i] = std::string(s[i].rbegin(), s[i].rend());

    std::vector<integer> dp(n, oo), pd(n, oo);
    dp[0] = 0;
    pd[0] = c[0];
    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] <= s[i])
            dp[i] = std::min(dp[i], dp[i-1]);

        if (t[i-1] <= s[i])
            dp[i] = std::min(dp[i], pd[i-1]);

        if (s[i-1] <= t[i] && dp[i-1] != oo)
            pd[i] = std::min(pd[i], dp[i-1] + c[i]);

        if (t[i-1] <= t[i] && pd[i-1] != oo)
            pd[i] = std::min(pd[i], pd[i-1] + c[i]);
    }

    if (dp[n-1] == oo && pd[n-1] == oo)
        return no_answer();

    answer(std::min(dp[n-1], pd[n-1]));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, c);

    return 0;
}
