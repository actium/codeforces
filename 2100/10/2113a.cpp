#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k, unsigned a, unsigned b, unsigned x, unsigned y)
{
    if (y < x) {
        std::swap(a, b);
        std::swap(x, y);
    }

    unsigned c = 0;
    {
        if (k >= a)
            c += 1 + (k - a) / x;

        if (k >= b + c * x)
            c += 1 + (k - b - c * x) / y;
    }
    answer(c);
}

void test_case()
{
    unsigned k, a, b, x, y;
    std::cin >> k >> a >> b >> x >> y;

    solve(k, a, b, x, y);
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
