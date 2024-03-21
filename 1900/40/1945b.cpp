#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer a, integer b, integer m)
{
    answer(m / a + m / b + 2);
}

void test_case()
{
    integer a, b, m;
    std::cin >> a >> b >> m;

    solve(a, b, m);
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
