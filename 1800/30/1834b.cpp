#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& lb, const std::string& ub)
{
    const size_t n = ub.length();

    if (lb.length() != n)
        return answer(ub[0] - '0' + 9 * (n - 1));

    size_t i = 0;
    while (i + 1 < n && lb[i] == ub[i])
        ++i;

    answer(ub[i] - lb[i] + 9 * (n - 1 - i));
}

void test_case()
{
    std::string lb, ub;
    std::cin >> lb >> ub;

    solve(lb, ub);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
