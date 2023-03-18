#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(int a, int b)
{
    a = abs(a), b = abs(b);

    answer(std::max(a, b) * 2 - (a != b));
}

void test_case()
{
    int a, b;
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
