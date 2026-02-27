#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned d)
{
    const unsigned k = d / m + 1;

    answer((n + k - 1) / k);
}

void test_case()
{
    unsigned n, m, d;
    std::cin >> n >> m >> d;

    solve(n, m, d);
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
