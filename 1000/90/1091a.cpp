#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t y, size_t b, size_t r)
{
    b = std::min(b, r - 1);
    y = std::min(y, b - 1);
    answer(3 * (y + 1));	// y + (y + 1) + ((y + 1) + 1);
}

int main()
{
    size_t y, b, r;
    std::cin >> y >> b >> r;

    solve(y, b, r);

    return 0;
}

