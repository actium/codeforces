#include <iostream>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(unsigned a, unsigned b, unsigned c, unsigned d)
{
    std::cout << "YES" << '\n';
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

void solve(unsigned n)
{
    if (n < 31)
        return no_answer();

    const unsigned k = n - 30;
    if (k == 6 || k == 10 || k == 14)
        answer(6, 10, 15, n - 31);
    else
        answer(6, 10, 14, n - 30);
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

