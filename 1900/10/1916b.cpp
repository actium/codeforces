#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    using integer = unsigned long long;

    integer c = std::lcm<integer>(a, b);
    if (c == b)
        c *= b / a;

    answer(c);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
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
