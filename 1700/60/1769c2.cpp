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

    std::vector<unsigned> dp[2];
    for (size_t i = 0; i < 2; ++i)
        dp[i].resize(n, 1);

    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            dp[0][i] = dp[0][i-1];
            dp[1][i] = std::max(dp[0][i-1] + 1, dp[1][i-1]);
        }
        if (a[i] == a[i-1] + 1) {
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
        }
        if (a[i] == a[i-1] + 2) {
            dp[0][i] = dp[1][i-1] + 1;
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        k = std::max(k, dp[0][i]);
        k = std::max(k, dp[1][i]);
    }

    answer(k);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}