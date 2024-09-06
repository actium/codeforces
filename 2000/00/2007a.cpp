#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned lb, unsigned ub)
{
    answer((ub - lb + lb % 2 + ub % 2) / 4);
}

void test_case()
{
    unsigned lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);
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
