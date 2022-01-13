#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned g, unsigned b)
{
    const unsigned m = (n + 1) / 2, p = g + b;

    const auto f = [=](integer x) {
        const integer c = x / p * g + std::min<unsigned>(x % p, g);

        return c >= m;
    };

    integer lb = 0, ub = 1ull * n * p;
    while (lb + 1 < ub) {
        const integer x = lb + (ub - lb) / 2;
        (f(x) ? ub : lb) = x;
    }

    answer(std::max<integer>(n, ub));
}

void test_case()
{
    unsigned n, g, b;
    std::cin >> n >> g >> b;

    solve(n, g, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
