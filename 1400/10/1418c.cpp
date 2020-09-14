#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> dp(n+2);
    for (size_t i = n-1; ~i; --i) {
        dp[i].first = a[i] + std::min(dp[i+1].second, a[i+1] + dp[i+2].second);
        dp[i].second = std::min(dp[i+1].first, dp[i+2].first);
    }

    answer(dp[0].first);
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

