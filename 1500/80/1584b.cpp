#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    answer((n * m + 2) / 3);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
