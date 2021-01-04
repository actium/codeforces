#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned s, unsigned i, unsigned x)
{
    if (s + x <= i)
        return answer(0);

    if (i + x < s)
        return answer(x + 1);

    answer(x - (x + i - s) / 2);
}

void test_case()
{
    unsigned s, i, x;
    std::cin >> s >> i >> x;

    solve(s, i, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

