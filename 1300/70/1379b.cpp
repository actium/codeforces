#include <iostream>

using integer = unsigned long long;

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned l, unsigned r, integer m)
{
    if (m / l == 0)
        return answer(l, l, 2 * l - m);

    for (unsigned a = l; ; ++a) {
        const unsigned d = m % a;
        if (d <= r - l)
            return answer(a, l + d, l);

        const unsigned e = (m / a + 1) * a - m;
        if (e <= r - l)
            return answer(a, l, l + e);
    }
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    integer m;
    std::cin >> m;

    solve(l, r, m);
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
