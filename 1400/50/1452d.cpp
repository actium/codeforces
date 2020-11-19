#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned M = 998244353;

    std::vector<unsigned> dp(n, 1);
    for (unsigned i = 2; i < n; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % M;

    unsigned long long t = dp.back();
    for (size_t i = 0; i < n; ++i)
        t = t * (M + 1) / 2 % M;

    answer(t);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
