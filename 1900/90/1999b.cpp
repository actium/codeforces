#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned check(unsigned a1, unsigned b1, unsigned a2, unsigned b2)
{
    return (a1 > b1) + (a2 > b2) > (a1 < b1) + (a2 < b2);
}

void solve(unsigned a1, unsigned a2, unsigned b1, unsigned b2)
{
    answer(check(a1, b1, a2, b2) + check(a1, b2, a2, b1) + check(a2, b1, a1, b2) + check(a2, b2, a1, b1));
}

void test_case()
{
    unsigned a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;

    solve(a1, a2, b1, b2);
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
