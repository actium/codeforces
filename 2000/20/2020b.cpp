#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer k)
{
    integer d = 1;
    for (integer x = 0; x != d; std::swap(d, x))
        d = std::sqrt(static_cast<long double>(k + x));

    answer(k + d);
}

void test_case()
{
    integer k;
    std::cin >> k;

    solve(k);
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
