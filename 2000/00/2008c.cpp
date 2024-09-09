#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned lb, unsigned ub)
{
    unsigned k = 0;
    for (unsigned d = 0; lb <= ub; lb += ++d)
        ++k;

    answer(k);
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
