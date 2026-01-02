#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k, unsigned x)
{
    answer(k * x + 1);
}

void test_case()
{
    unsigned k, x;
    std::cin >> k >> x;

    solve(k, x);
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
