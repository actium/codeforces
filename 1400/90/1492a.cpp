#include <algorithm>
#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer p, integer a, integer b, integer c)
{
    if (p % a == 0 || p % b == 0 || p % c == 0)
        return answer(0);

    answer(std::min({ a - p % a, b - p % b, c - p % c }));
}

void test_case()
{
    integer p, a, b, c;
    std::cin >> p >> a >> b >> c;

    solve(p, a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

