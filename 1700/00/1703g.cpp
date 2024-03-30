#include <iostream>
#include <vector>

using integer = long long;

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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<std::vector<integer>> dp(31, std::vector<integer>(1 + n));
    for (size_t i = 0; i < n; ++i) {
        dp[0][i+1] = dp[0][i] + a[i] - k;

        for (unsigned j = 1; j < 31; ++j) {
            const unsigned d = a[i] >> j;
            dp[j][i+1] = std::max(dp[j][i] + d - k, dp[j-1][i] + d);
        }

        dp[30][i+1] = std::max(dp[30][i+1], dp[30][i]);
    }

    integer x = dp[0][n];
    for (size_t i = 1; i < 31; ++i)
        x = std::max(x, dp[i][n]);

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
