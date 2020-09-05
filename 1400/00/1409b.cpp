#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned x, unsigned y, unsigned n)
{
    const auto evaluate = [](unsigned a, unsigned b, unsigned x, unsigned y, unsigned n) {
        const unsigned k1 = std::min(a - x, n);
        a -= k1, n -= k1;

        const unsigned k2 = std::min(b - y, n);
        b -= k2, n -= k2;

        return 1ull * a * b;
    };

    answer(std::min(evaluate(a, b, x, y, n), evaluate(b, a, y, x, n)));
}

void test_case()
{
    unsigned a, b, x, y, n;
    std::cin >> a >> b >> x >> y >> n;

    solve(a, b, x, y, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

