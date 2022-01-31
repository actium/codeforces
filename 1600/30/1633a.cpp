#include <iostream>

void answer(unsigned n)
{
    std::cout << n << '\n';
}

void solve(unsigned n)
{
    const unsigned r = n % 7;
    if (n % 10 >= r)
        answer(n - r);
    else
        answer(n + 7 - r);
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
