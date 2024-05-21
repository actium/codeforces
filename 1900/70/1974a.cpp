#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y)
{
    const unsigned b = (y + 1) / 2;

    x -= std::min(x, b * 15 - y * 4);

    answer(b + (x + 14) / 15);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
