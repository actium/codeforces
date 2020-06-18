#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t k2, size_t k3, size_t k5, size_t k6)
{
    const size_t c256 = std::min({ k2, k5, k6 });
    const size_t c32 = std::min(k3, k2 - c256);
    answer(c256 * 256 + c32 * 32);
}

int main()
{
    size_t k2, k3, k5, k6;
    std::cin >> k2 >> k3 >> k5 >> k6;

    solve(k2, k3, k5, k6);

    return 0;
}

