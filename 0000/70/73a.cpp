#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, unsigned z, unsigned k)
{
    if (x > y)
        std::swap(x, y);
    if (y > z)
        std::swap(y, z);
    if (x > y)
        std::swap(x, y);

    const unsigned a = std::min(x - 1, k / 3), b = std::min(y - 1, (k - a) / 2), c = std::min(z - 1, k - a - b);

    answer((a + 1ull) * (b + 1) * (c + 1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned x, y, z, k;
    std::cin >> x >> y >> z >> k;

    solve(x, y, z, k);

    return 0;
}
