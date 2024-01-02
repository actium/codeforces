#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer k)
{
    integer s = 0;
    for (integer p = 1; k != 0; k /= 9, p *= 10) {
        const integer d = k % 9;
        s += (d + (d > 3)) * p;
    }

    answer(s);
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
