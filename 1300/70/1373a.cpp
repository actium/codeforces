#include <iostream>

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    if (a >= c)
        return answer(-1, b);

    const unsigned long long d = 1ull * a * b;
    if (d <= c)
        return answer(1, -1);

    answer(1, b);
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

