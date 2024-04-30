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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<std::vector<integer>> dp(1 + n, std::vector<integer>(1 + k));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= k; ++j) {
            dp[i+1][j] = dp[i][j] + a[i];

            unsigned b = a[i];
            for (size_t d = 1; d <= j && d <= i; ++d) {
                b = std::min(b, a[i-d]);
                dp[i+1][j] = std::min(dp[i+1][j], b * (d + 1ull) + dp[i-d][j-d]);
            }
        }
    }

    answer(dp[n][k]);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
