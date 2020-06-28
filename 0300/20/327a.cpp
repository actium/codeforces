#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    size_t ones = 0;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];

        if (a[i] == 1)
            ++ones;
    }

    using pair_t = std::pair<size_t, size_t>;
    std::vector<std::vector<pair_t>> dp(n, std::vector<pair_t>(n, { 0, 0 }));
    dp[0][0].first = 1 - a[0];
    dp[0][0].second = a[0];

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            if (j == 0)
                continue;

            dp[i][j].first = dp[i][j-1].first + 1 - a[j];
            dp[i][j].second = dp[i][j-1].second + a[j];
        }
    }

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            count = std::max(count, ones - dp[i][j].second + dp[i][j].first);
        }
    }

    answer(count);

    return 0;
}

