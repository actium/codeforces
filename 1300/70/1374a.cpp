#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, unsigned y, unsigned n)
{
    answer((n - y) / x * x + y);
}

void test_case()
{
    unsigned x, y, n;
    std::cin >> x >> y >> n;

    solve(x, y, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


