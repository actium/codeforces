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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::vector<unsigned>> dp(1+n, std::vector<unsigned>(3));
    for (size_t i = 0; i < n; ++i) {
        dp[i+1][0] = std::min({ dp[i][0], dp[i][1], dp[i][2] }) + 1;
        dp[i+1][1] = dp[i][0] + 1;
        dp[i+1][2] = dp[i][0] + 1;

        if (a[i] == 1 || a[i] == 3) {
            dp[i+1][0] = std::min(dp[i+1][0], dp[i][1]);
            dp[i+1][2] = std::min(dp[i+1][2], dp[i][1]);
        }

        if (a[i] == 2 || a[i] == 3) {
            dp[i+1][0] = std::min(dp[i+1][0], dp[i][2]);
            dp[i+1][1] = std::min(dp[i+1][1], dp[i][2]);
        }
    }

    answer(std::min({ dp[n][0], dp[n][1], dp[n][2] }));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
