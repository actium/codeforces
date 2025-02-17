#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> dp[2];
    for (size_t i = 0; i < 2; ++i)
        dp[i].resize(1+n);

    dp[0][0].first = 1;
    for (size_t i = 0; i < n; ++i) {
        if (dp[0][i].second == a[i])
            dp[0][i+1].first += dp[0][i].first;
        if (dp[1][i].second == a[i])
            dp[0][i+1].first += dp[1][i].first;

        dp[0][i+1].first %= M;
        dp[0][i+1].second = a[i];

        if (dp[0][i].first != 0) {
            dp[1][i+1].first = dp[0][i].first;
            dp[1][i+1].second = dp[0][i].second + 1;
        }
    }

    answer((dp[0][n].first + dp[1][n].first) % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
