#include <iostream>

using integer = unsigned long long;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

integer sum(integer x)
{
    return x * (x + 1) / 2;
}

void solve(integer x)
{
    unsigned k = 0;
    for (integer b = 1, s; s = sum(b), s <= x; x -= s, b = b << 1 | 1)
        ++k;

    answer(k);
}

void test_case()
{
    integer x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

