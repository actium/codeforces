#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y, integer z)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (b == 1)
        return no_answer();

    const integer z = 1ull * a * b;
    answer(a, z, a + z);
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
