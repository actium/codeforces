#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t n, size_t l, size_t r)
{
    const unsigned k1 = (1 << l) - 1;
    const unsigned k2 = (1 << r) - 1;
    const unsigned m = 1 << (r - 1);

    answer(k1 + (n - l) * 1, k2 + (n - r) * m);
}

int main()
{
    size_t n, l, r;
    std::cin >> n >> l >> r;

    solve(n, l, r);

    return 0;
}

