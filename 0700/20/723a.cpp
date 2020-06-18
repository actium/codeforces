#include <algorithm>
#include <array>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::array<unsigned, 3>& x)
{
    std::sort(x.begin(), x.end());

    answer(x[1] - x[0] + x[2] - x[1]);
}

int main()
{
    std::array<unsigned, 3> x;
    std::cin >> x[0] >> x[1] >> x[2];

    solve(x);

    return 0;
}

