#include <iostream>

using integer = long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned u, unsigned v)
{
    answer(-1ll * u * u, 1ll * v * v);
}

void test_case()
{
    unsigned u, v;
    std::cin >> u >> v;

    solve(u, v);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
