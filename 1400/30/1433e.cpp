#include <iostream>

using integer = unsigned long long;

integer f(unsigned n)
{
    static integer dp[21] = {};

    if (n == 0)
        return 1;

    if (dp[n] == 0)
        dp[n] = n * f(n-1);

    return dp[n];
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(2 * f(n - 1) / n);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

