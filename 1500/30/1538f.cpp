#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r)
{
    const auto f = [](unsigned n) {
        unsigned q = 0;
        for (unsigned k = 1; k <= n; k *= 10)
            q += n / k;

        return q;
    };

    answer(f(r) - f(l));
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
