#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a == b)
        return answer((a + b) / 3);

    if (a > b)
        std::swap(a, b);

    if (2 * a <= b)
        return answer(a);

    const unsigned k = 2 * a - b;
    answer(2 * k / 3 + a - k);
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

