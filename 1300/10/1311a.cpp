#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a == b)
        return answer(0);

    if (a > b && (a - b) % 2 == 0 || a < b && (b - a) % 2 == 1)
        return answer(1);

    answer(2);
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

