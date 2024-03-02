#include <iostream>

unsigned count(unsigned n, size_t x)
{
    constexpr unsigned c[] = { 15, 10, 6, 3, 1 };

    if (c[x] == 1)
        return n;

    unsigned q = n / c[x], k = ~0u;
    for (unsigned d = 0, ub = std::min<unsigned>(5, q); d <= ub; ++d) {
        const unsigned u = q - d;
        k = std::min(k, u + count(n - u * c[x], x + 1));
    }
    return k;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(count(n, 0));
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
