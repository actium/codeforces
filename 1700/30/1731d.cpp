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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    const auto check = [&](unsigned k) {
        std::vector<std::vector<unsigned>> dp(n, std::vector<unsigned>(m));
        {
            for (size_t i = 0; i < n; ++i)
                dp[i][0] = (a[i][0] >= k);
            for (size_t j = 1; j < m; ++j)
                dp[0][j] = (a[0][j] >= k);
            for (size_t i = 1; i < n; ++i) {
                for (size_t j = 1; j < m; ++j) {
                    if (a[i][j] >= k)
                        dp[i][j] = std::min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1;
                }
            }
        }

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (dp[i][j] >= k)
                    return true;
            }
        }
        return false;
    };

    unsigned lb = 0, ub = std::min(n, m) + 1;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
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
