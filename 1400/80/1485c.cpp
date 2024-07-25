#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y)
{
    integer k = 0;
    for (unsigned i = 1; i < std::min(y, (x - i) / i); ++i)
        k += std::min(y, (x - i) / i) - i;

    answer(k);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
