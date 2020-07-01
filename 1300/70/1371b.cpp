#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned r)
{
    const integer k = std::min(n - 1, r);
    answer(k * (k + 1) / 2 + (r >= n));
}

void test_case()
{
    unsigned n, r;
    std::cin >> n >> r;

    solve(n, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

