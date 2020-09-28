#include <iostream>

#include <cmath>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    const unsigned k = sqrt(n);

    answer(k - 1 + (n - 1) / k);
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

