#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned w, unsigned h)
{
    std::vector<std::vector<unsigned>> dp(h, std::vector<unsigned>(w));

    dp[0][0] = 4;

    for (size_t x = 1; x < w; ++x)
        dp[0][x] = dp[0][x-1] * 2 % M;

    for (size_t y = 1; y < h; ++y) {
        dp[y][0] = dp[y-1][0] * 2 % M;

        for (size_t x = 1; x < w; ++x)
            dp[y][x] = (dp[y-1][x] + dp[y][x-1]) % M;
    }

    answer(dp[h-1][w-1]);
}

int main()
{
    unsigned w, h;
    std::cin >> w >> h;

    solve(w, h);

    return 0;
}

