#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned x, unsigned y, unsigned d)
{
    constexpr unsigned oo = ~0u;

    if (abs(x - y) % d == 0)
        return answer(abs(x - y) / d);

    unsigned k1 = oo;
    if ((y - 1) % d == 0)
        k1 = (x - 1 + d - 1) / d + (y - 1) / d;

    unsigned k2 = oo;
    if ((n - y) % d == 0)
        k2 = (n - x + d - 1) / d + (n - y) / d;

    if (k1 != oo || k2 != oo)
        return answer(std::min(k1, k2));

    no_answer();
}

void test_case()
{
    unsigned n, x, y, d;
    std::cin >> n >> x >> y >> d;

    solve(n, x, y, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

