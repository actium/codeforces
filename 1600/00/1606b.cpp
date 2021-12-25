#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer k)
{
    integer c = 0, s = 1;
    for (const auto b = std::min(n, k); s < b; s *= 2)
        ++c;

    if (s < n)
        c += (n - s + k - 1) / k;

    answer(c);
}

void test_case()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
