#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned n)
{
    answer(n % 2 == 0 ? 0 : x);
}

void test_case()
{
    unsigned x, n;
    std::cin >> x >> n;

    solve(x, n);
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
