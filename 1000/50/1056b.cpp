#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    std::vector<integer> f(m);
    for (unsigned i = 1; i <= m; ++i)
        f[i * i % m] += n / m + (n % m >= i);

    integer q = f[0] * f[0];
    for (unsigned i = 1; i < m; ++i)
        q += f[i] * f[m-i];

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
