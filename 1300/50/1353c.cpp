#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    integer count = 0;
    for (integer r = 0; r <= (n - 1) / 2; ++r)
        count += 8 * r * r;

    answer(count);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

