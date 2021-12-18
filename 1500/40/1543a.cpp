#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(integer a, integer b)
{
    if (a > b)
        std::swap(a, b);

    const auto d = b - a;
    if (d == 0)
        return answer(0, 0);

    const auto r = a % d;
    answer(d, std::min(r, d - r));
}

void test_case()
{
    integer a, b;
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
