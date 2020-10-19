#include <algorithm>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned c, unsigned m, unsigned x)
{
    const unsigned ub = (c + m + x) / 3;
    if (c > ub) {
        x += c - ub;
        c = ub;
    }
    if (m > ub) {
        x += m - ub;
        m = ub;
    }

    answer(std::min({ c, m, x }));
}

void test_case()
{
    unsigned c, m, x;
    std::cin >> c >> m >> x;

    solve(c, m, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

