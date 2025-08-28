#include <iostream>

using integer = unsigned long long;

unsigned t[19];

void initialize()
{
    t[0] = 3;
    for (size_t i = 1, x = 1; i < 19; ++i, x *= 3)
        t[i] = 3 * t[i-1] + x;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    integer c = 0;
    for (size_t i = 0; n != 0; n /= 3)
        c += integer(n % 3) * t[i++];

    answer(c);
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

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
