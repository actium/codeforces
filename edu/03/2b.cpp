#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k, unsigned j)
{
    if (j == 0)
        return answer(0);

    unsigned i = 1;
    while ((j - i) % (2 * i) != 0)
        i *= 2;

    answer(i - 1);
}

void test_case()
{
    unsigned k, j;
    std::cin >> k >> j;

    solve(k, j);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
