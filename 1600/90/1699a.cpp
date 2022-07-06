#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 1)
        return no_answer();

    answer(0, 0, n / 2);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
