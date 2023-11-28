#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned m)
{
    const unsigned g = std::gcd(n, m);
    if (__builtin_popcount(m / g) != 1)
        return no_answer();

    integer k = 0;
    for (unsigned r = n % m; r != 0; r %= m) {
        k += r;
        r *= 2;
    }

    answer(k);
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
