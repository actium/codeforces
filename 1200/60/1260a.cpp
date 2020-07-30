#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned c, unsigned sum)
{
    const unsigned n = sum % c;
    const unsigned x = sum / c;
    const unsigned y = x + 1;

    answer(n * y * y + (c - n) * x * x);
}

void test_case()
{
    unsigned c, sum;
    std::cin >> c >> sum;

    solve(c, sum);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


