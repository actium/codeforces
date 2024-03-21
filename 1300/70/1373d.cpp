#include <algorithm>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> dp(4);
    for (size_t i = 0; i < n; i += 2) {
        dp = {
            dp[0] + a[i],
            std::max(dp[0], dp[1]) + (i + 1 < n ? a[i+1] : 0),
            std::max(dp[0], dp[2]) + (i > 0 ? a[i-1] : 0),
            std::max({ dp[1], dp[2], dp[3] }) + a[i],
        };
    }

    answer(*std::max_element(dp.begin(), dp.end()));
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
