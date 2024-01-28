#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned n)
{
    const unsigned ub = x / n;

    unsigned v = 1;
    for (unsigned i = 1; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        if (i <= ub)
            v = std::max(v, i);

        if (x / i <= ub)
            v = std::max(v, x / i);
    }

    answer(v);
}

void test_case()
{
    unsigned x, n;
    std::cin >> x >> n;

    solve(x, n);
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
