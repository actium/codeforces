#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& a, size_t m, size_t k)
{
    const size_t n = a.size();

    std::vector<integer> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    std::vector<std::vector<integer>> dp(1+n, std::vector<integer>(1+k));
    for (size_t i = m; i <= n; ++i) {
        for (size_t j = 1; j <= k; ++j)
            dp[i][j] = std::max(dp[i-1][j], dp[i-m][j-1] + p[i] - p[i-m]);
    }

    answer(dp[n][k]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}
