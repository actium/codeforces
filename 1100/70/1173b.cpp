#include <iostream>

void solve(unsigned n)
{
    const unsigned m = 1 + n / 2;
    std::cout << m << '\n';

    for (unsigned i = 0; i < m; ++i)
        std::cout << 1 << ' ' << 1+i << '\n';

    for (unsigned i = m; i < n; ++i)
        std::cout << 2+i-m << ' ' << m << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

