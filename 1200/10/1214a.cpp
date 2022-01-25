#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned d, unsigned e)
{
    unsigned r = n;
    for (unsigned i = 0; i * 5 * e <= n; ++i)
        r = std::min(r, (n - i * 5 * e) % d);

    answer(r);
}

int main()
{
    unsigned n, d, e;
    std::cin >> n >> d >> e;

    solve(n, d, e);

    return 0;
}
