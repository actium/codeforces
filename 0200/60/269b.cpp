#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> dp(n, 1);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (s[j] <= s[i])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }

    unsigned d = 0;
    for (const unsigned x : dp)
        d = std::max(d, x);

    answer(n - d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < n; ++i) {
        double x;
        std::cin >> s[i] >> x;
    }

    solve(s);

    return 0;
}
