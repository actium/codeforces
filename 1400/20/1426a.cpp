#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x)
{
    answer(n < 3 ? 1 : 2 + (n - 3) / x);
}

void test_case()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

