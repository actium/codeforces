#include <algorithm>
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

void solve(std::vector<unsigned>& t)
{
    const size_t n = t.size();

    std::sort(t.begin(), t.end());

    const auto delta = [](unsigned a, unsigned b) {
        return a < b ? b - a : a - b;
    };

    std::vector<unsigned> dp(1 + n, ~0u);
    for (size_t j = 1; j <= n; ++j)
        dp[j] = std::min(dp[j-1], delta(t[0], j));

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j <= n; ++j)
            dp[j] = std::min(dp[j-1], dp[j] + delta(t[i], i + j));
    }

    answer(dp[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

