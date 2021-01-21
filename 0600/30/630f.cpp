#include <iostream>

using integer = unsigned long long;

integer C(int n, int r)
{
    static integer dp[778][8] = {};

    if (n < 0 || r < 0)
        return 0;

    if (n == r)
        return 1;

    if (dp[n][r] == 0)
        dp[n][r] = C(n-1, r) + C(n-1, r-1);

    return dp[n][r];
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(C(n, 7) + C(n, 6) + C(n, 5));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

