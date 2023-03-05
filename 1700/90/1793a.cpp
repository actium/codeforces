#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << std::endl;
}

void solve(integer a, integer b, unsigned n, unsigned m)
{
    const unsigned q = n / (m + 1);
    const unsigned r = n - q * (m + 1);

    answer(std::min(q * m * a + r * std::min(a, b), n * b));
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    unsigned n, m;
    std::cin >> n >> m;

    solve(a, b, n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
