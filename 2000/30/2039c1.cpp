#include <iostream>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, integer m)
{
    unsigned k = 0;
    for (unsigned i = 1; i <= x; ++i) {
        const unsigned y = x ^ i;
        if (y < 1 || y > m)
            continue;

        k += (x % i == 0 || y % i == 0);
    }

    answer(k);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    integer m;
    std::cin >> m;

    solve(x, m);
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
