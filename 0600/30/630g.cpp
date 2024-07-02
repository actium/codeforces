#include <array>
#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

template <unsigned K>
integer count(unsigned n)
{
    std::vector<std::array<integer, 1+K>> dp(1+n);
    dp[0][0] = 1;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j <= K; ++j) {
            for (unsigned k = j; k <= K; ++k)
                dp[i+1][k] += dp[i][j];
        }
    }
    return dp[n][K];
}

void solve(unsigned n)
{
    answer(count<3>(n) * count<5>(n));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
