#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned s)
{
    const unsigned m = n / 2 + 1;

    answer(s / m);
}

void test_case()
{
    unsigned n, s;
    std::cin >> n >> s;

    solve(n, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
