#include <iostream>

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned l, unsigned r)
{
    const unsigned y = 2 * l;
    if (y > r)
        answer(-1, -1);
    else
        answer(l, y);
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

