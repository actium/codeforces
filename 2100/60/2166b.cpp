#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned n)
{
    answer(b == a || 1ull * b * n <= a ? 1 : 2);
}

void test_case()
{
    unsigned a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);
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
