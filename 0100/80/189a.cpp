#include <iostream>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t a, size_t b, size_t c)
{
    // dp[i] gives max number of pieces that can be obtained by cutting ribbon of length i
    // into pieces of length a, b or c
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (size_t i = 0; i < n; ++i) {
        if (dp[i] == -1)
            continue;	// it is not possible to cut ribbon of length i into pieces

        if (i + a <= n)
            dp[i + a] = std::max(dp[i + a], dp[i] + 1);

        if (i + b <= n)
            dp[i + b] = std::max(dp[i + b], dp[i] + 1);

        if (i + c <= n)
            dp[i + c] = std::max(dp[i + c], dp[i] + 1);
    }

    // now dp[n] contains max possible number of pieces for ribbon of length n
    answer(dp[n]);
}

int main()
{
    size_t n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);

    return 0;
}

