#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a >= b)
        return answer(a);

    answer(2 * a > b ? 2 * a - b : 0);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
