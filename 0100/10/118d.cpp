#include <iostream>

constexpr unsigned M = 100000000;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n1, unsigned n2, unsigned k1, unsigned k2)
{
    unsigned dp[101][101][11][11] = {};
    dp[0][0][0][0] = 1;
    for (unsigned i1 = 0; i1 <= n1; ++i1) {
        for (unsigned i2 = 0; i2 <= n2; ++i2) {
            for (unsigned q1 = 0; q1 <= k1; ++q1) {
                for (unsigned q2 = 0; q2 <= k2; ++q2) {
                    if (i1 < n1 && q1 < k1)
                        dp[i1+1][i2][q1+1][0] = (dp[i1+1][i2][q1+1][0] + dp[i1][i2][q1][q2]) % M;

                    if (i2 < n2 && q2 < k2)
                        dp[i1][i2+1][0][q2+1] = (dp[i1][i2+1][0][q2+1] + dp[i1][i2][q1][q2]) % M;
                }
            }
        }
    }

    unsigned c = 0;
    for (unsigned q1 = 0; q1 <= k1; ++q1) {
        for (unsigned q2 = 0; q2 <= k2; ++q2)
            c = (c + dp[n1][n2][q1][q2]) % M;
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n1, n2, k1, k2;
    std::cin >> n1 >> n2 >> k1 >> k2;

    solve(n1, n2, k1, k2);

    return 0;
}
