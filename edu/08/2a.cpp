#include <algorithm>
#include <iostream>

constexpr size_t K = 44750;

unsigned b[K];

void initialize()
{
    for (unsigned i = 0; i < K; ++i)
        b[i] = i * (i - 1);
}

void answer(unsigned n)
{
    std::cout << n << '\n';
}

void solve(unsigned m)
{
    answer(std::lower_bound(b, b + K, 2 * m) - b);
}

void test_case()
{
    unsigned m;
    std::cin >> m;

    solve(m);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
