#include <iostream>

void print(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m)
{
    const unsigned k = 1 + (n - 1) + (m - 1);
    std::cout << k << '\n';

    print(1, 1);

    for (unsigned i = 2; i <= n; ++i)
        print(i, 1);

    for (unsigned i = 2; i <= m; ++i)
        print(1, i);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

