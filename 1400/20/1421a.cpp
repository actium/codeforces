#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer(a ^ b);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

