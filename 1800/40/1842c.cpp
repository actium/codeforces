#include <iostream>
#include <vector>

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

    std::vector<std::pair<unsigned, size_t>> dp(1 + n);
    std::vector<size_t> x(1 + n, n);
    for (size_t i = 0; i < n; ++i) {
        dp[i+1] = dp[i];

        const size_t j = x[a[i]];
        if (j < n && dp[j].first + i - j + 1 > dp[i+1].first) {
            dp[i+1].first = dp[j].first + i - j + 1;
            dp[i+1].second = i;
        }
        if (j < n && a[j] == a[i] && dp[j+1].first + i - j > dp[i+1].first) {
            dp[i+1].first = dp[j+1].first + i - j;
            dp[i+1].second = i;
        }

        x[a[i]] = i;
    }

    answer(dp[n].first);
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
