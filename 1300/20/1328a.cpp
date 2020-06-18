#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a <= b)
        return answer(b - a);

    const unsigned r = a % b;
    answer(r != 0 ? b - r : 0);
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

