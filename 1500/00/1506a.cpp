#include <iostream>

void answer(uint64_t x)
{
    std::cout << x << '\n';
}

void solve(uint64_t n, uint64_t m, uint64_t x)
{
    const auto c = (x - 1) / n;
    const auto r = (x - 1) % n;

    answer(1 + r * m + c);
}

void test_case()
{
    uint64_t n, m, x;
    std::cin >> n >> m >> x;

    solve(n, m, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
