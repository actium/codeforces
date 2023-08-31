#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned x = 0;
    for (unsigned i = 1; i <= n; ++i) {
        unsigned s = 0, d = 0;
        for (unsigned j = 1; j <= n; ++j) {
            const unsigned p = (j < i ? j : n - (j - i));
            s += j * p;
            d = std::max(d, j * p);
        }

        x = std::max(x, s - d);
    }

    answer(x);
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
