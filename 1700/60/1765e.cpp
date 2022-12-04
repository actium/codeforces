#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    answer(a > b ? 1 : (n + a - 1) / a);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
