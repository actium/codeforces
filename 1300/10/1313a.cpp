#include <algorithm>
#include <array>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::array<unsigned, 3>& x)
{
    std::sort(x.begin(), x.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (size_t i = 0; i < 3; ++i) {
        if (x[i] > 0)
            ++k, --x[i];
    }

    if (x[0] > 0 && x[1] > 0)
        ++k, --x[0], --x[1];
    if (x[0] > 0 && x[2] > 0)
        ++k, --x[0], --x[2];
    if (x[1] > 0 && x[2] > 0)
        ++k, --x[1], --x[2];

    if (x[0] > 0 && x[1] > 0 && x[2] > 0)
        ++k;

    answer(k);
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

