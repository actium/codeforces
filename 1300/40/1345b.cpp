#include <iostream>

unsigned f(unsigned n)
{
    unsigned k = 0;
    for (unsigned h = 0, m = 0; m <= n; ++h, m = (3 * h * h + h) / 2)
        k = m;

    return k;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    while (n > 1) {
        n -= f(n);
        ++k;
    }

    answer(k);
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

