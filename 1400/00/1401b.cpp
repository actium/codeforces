#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned x1, unsigned y1, unsigned z1, unsigned x2, unsigned y2, unsigned z2)
{
    const unsigned k21 = std::min(z1, y2);
    z1 -= k21, y2 -= k21;

    const unsigned k10 = std::min(y1, x2);
    y1 -= k10, x2 -= k10;

    const unsigned k02 = std::min(x1, z2);
    x1 -= k02, z2 -= k02;

    answer(k21 * 2 - std::min(y1, z2) * 2);
}

void test_case()
{
    unsigned x1, y1, z1;
    std::cin >> x1 >> y1 >> z1;

    unsigned x2, y2, z2;
    std::cin >> x2 >> y2 >> z2;

    solve(x1, y1, z1, x2, y2, z2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

