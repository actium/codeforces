#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    const auto evaluate = [=](unsigned m) {
        return (a + m - 1) / m + (b + m - 1) / m + (m - 1);
    };

    unsigned k = ~0u;
    for (unsigned i = 1; i < 44722; ++i)
        k = std::min(k, evaluate(i));

    answer(k);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
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
