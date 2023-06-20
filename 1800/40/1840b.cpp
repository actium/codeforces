#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    const unsigned ub = k < 30 ? 1 << k : 1000000001;

    answer(std::min(n + 1, ub));
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
