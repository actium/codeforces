#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned k)
{
    const unsigned x = (k == 0 || k == n ? 0 : 1);
    const unsigned y = std::min(n - k, 2 * k);

    answer(x, y);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

