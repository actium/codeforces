#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t x)
{
    answer((x + 6) / 7);
}

void test_case()
{
    size_t x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

