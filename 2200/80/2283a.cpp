#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(int lb, int ub)
{
    if (lb > 0 || ub < 0)
        return answer(ub - lb);

    if (-lb == ub)
        return answer(0);
    
    answer(std::abs(lb + ub) - 1);
}

void test_case()
{
    int lb, ub;
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
