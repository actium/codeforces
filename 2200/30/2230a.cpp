#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    const auto c1 = 1ull * n * a;
    const auto c2 = n / 3ull * b + std::min(n % 3 * a, b);

    answer(std::min(c1, c2));
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
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
