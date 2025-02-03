#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r)
{
    answer(r - l + (r == 1));
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
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
