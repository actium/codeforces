#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y)
{
    if (x == 0 && y == 0)
        return answer(0);

    const unsigned d = x * x + y * y;

    unsigned q = 0;
    while (q * q < d)
        ++q;

    answer(q * q == d ? 1 : 2);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
