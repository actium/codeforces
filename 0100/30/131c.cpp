#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned t)
{
    integer c[31][31] = {};
    for (unsigned i = 1; i <= 30; ++i) {
        c[i][0] = c[i][i] = 1;

        for (unsigned j = 1; j < i; ++j)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }

    integer k = 0;
    for (unsigned i = 4; i <= n && i < t; ++i) {
        const unsigned j = t - i;
        if (j <= m)
            k += c[n][i] * c[m][j];
    }

    answer(k);
}

int main()
{
    unsigned n, m, t;
    std::cin >> n >> m >> t;

    solve(n, m, t);

    return 0;
}
