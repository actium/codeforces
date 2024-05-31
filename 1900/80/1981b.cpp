#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    const unsigned lb = n < m ? 0 : n - m, ub = n + m;

    for (unsigned i = 1 << 30; i != 0; i >>= 1) {
        if (lb / i != ub / i)
            n |= i;
    }

    answer(n);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
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
