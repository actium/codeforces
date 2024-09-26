#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    const unsigned b = std::min(x, y);

    answer((n + b - 1) / b);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    solve(n, x, y);
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
