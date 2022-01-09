#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r)
{
    const auto z = [](unsigned x, unsigned p) {
        const unsigned d = 1 << p, b = 1 << (p - 1);
        return (x + 1) / d * b + std::min((x + 1) % d, b);
    };

    unsigned k = r - l + 1;
    for (unsigned i = 1; i < 20; ++i)
        k = std::min(k, z(r, i) - z(l-1, i));

    answer(k);
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
