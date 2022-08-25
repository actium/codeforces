#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const unsigned long long x = 1ull * a * d, y = 1ull * b * c;
    if (x == y)
        return answer(0);

    if (x == 0 || y == 0)
        return answer(1);

    answer(std::max(x, y) % std::min(x, y) == 0 ? 1 : 2);
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
