#include <iostream>
#include <numeric>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer(std::gcd(a, b) == 1 ? "Finite" : "Infinite");
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

