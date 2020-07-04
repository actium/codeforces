#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned n)
{
    const unsigned x[3] = { a, b, a ^ b };
    answer(x[n % 3]);
}

void test_case()
{
    unsigned a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

