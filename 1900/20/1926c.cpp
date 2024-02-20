#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned s = 0, t = 0;
    for (unsigned p = 10; p <= n; p *= 10) {
        s += n / p;
        t += (1 + n / p) * (n / p) * p;
    }

    answer(((n + 1) * (n - 18 * s) + 9 * t) / 2);
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
