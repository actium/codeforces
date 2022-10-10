#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a > b)
        std::swap(a, b);

    unsigned t = 0;
    while (a < b)
        a += ++t;
    
    if ((a - b) % 2 == 0)
        return answer(t);

    answer(t + 1 + t % 2);
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
