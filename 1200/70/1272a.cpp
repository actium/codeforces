#include <algorithm>
#include <array>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::array<unsigned, 3>& x)
{
    std::sort(x.begin(), x.end());

    const unsigned d = x[2] - x[1] + x[2] - x[0] + x[1] - x[0];
    answer(d - std::min(d, 4u));
}

void test_case()
{
    std::array<unsigned, 3> x;
    std::cin >> x[0] >> x[1] >> x[2];

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

