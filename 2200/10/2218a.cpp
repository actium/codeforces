#include <iostream>

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(int x)
{
    answer(x);
}

void test_case()
{
    int x;
    std::cin >> x;

    solve(x);
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
