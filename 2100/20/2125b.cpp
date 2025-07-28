#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(integer a, integer b, integer k)
{
    const integer g = std::gcd(a, b);

    answer(a / g <= k && b / g <= k ? 1 : 2);
}

void test_case()
{
    integer a, b, k;
    std::cin >> a >> b >> k;

    solve(a, b, k);
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
