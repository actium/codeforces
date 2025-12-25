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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& c)
{
    const size_t n = a.size();

    std::vector<unsigned> b(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for (size_t i = 0; i < n; ++i)
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    std::vector<integer> dp(n);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != 0)
            dp[0] += c[i];

        for (size_t j = 1; j < n; ++j)
            dp[j] = std::min(dp[j-1], dp[j] + (j != a[i] ? c[i] : 0));
    }

    integer v = dp[0];
    for (size_t i = 1; i < n; ++i)
        v = std::min(v, dp[i]);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), c(n);
    std::cin >> a >> c;

    solve(a, c);
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
