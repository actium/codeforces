#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t c)
{
    const size_t x = std::min(c / 2, b);
    const size_t y = std::min(x / 2, a);

    answer(7 * y); // 1 * y + 2 * y + 4 * y;
}

int main()
{
    size_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

