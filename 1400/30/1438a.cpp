#include <iostream>

void solve(unsigned n)
{
    for (std::cout << 1; --n > 0; std::cout << ' ' << 1);

    std::cout << '\n';
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

