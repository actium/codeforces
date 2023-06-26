#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k, integer g)
{
    const integer x = (g - 1) / 2;
    if (x * n >= k * g)
        return answer(k * g);

    integer b = x * (n - 1), d = (k * g - b) % g;
    if (d * 2 >= g)
        b -= g;

    answer(b + d);
}

void test_case()
{
    unsigned n, k, g;
    std::cin >> n >> k >> g;

    solve(n, k, g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
