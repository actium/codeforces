#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned l, unsigned r)
{
    unsigned k = 1;
    while ((l << k) <= r)
        ++k;

    const unsigned b = r / (1 << k - 1);

    unsigned q = b - l + 1;
    if (k > 1) {
        const unsigned c = r / (3 << k - 2);
        if (c >= l)
            q += (k - 1) * (c - l + 1);
    }

    answer(k, q);
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
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
