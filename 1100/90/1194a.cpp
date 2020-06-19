#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t x)
{
    answer(x * 2);
}

void test_case()
{
    size_t n, x;
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

