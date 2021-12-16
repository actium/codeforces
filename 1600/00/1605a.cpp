#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a1, unsigned a2, unsigned a3)
{
    answer((a1 + a2 + a3) % 3 != 0);
}

void test_case()
{
    unsigned a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;

    solve(a1, a2, a3);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
