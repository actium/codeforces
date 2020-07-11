#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

int ps(int x)
{
    return (x % 2 == 0 ? 1 : -1) * (x + 1) / 2;
}

void solve(int l, int r)
{
    answer(ps(r) - ps(l-1));
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

