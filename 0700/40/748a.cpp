#include <iostream>

void answer(size_t x, size_t y, char z)
{
    std::cout << 1 + x << ' ' << 1 + y << ' ' << z << '\n';
}

void solve(size_t n, size_t m, size_t k)
{
    const size_t x = (k - 1) / (2 * m);
    const size_t y = (k - 1) % (2 * m);

    answer(x, y / 2, (y % 2 == 0 ? 'L' : 'R'));
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);

    return 0;
}

