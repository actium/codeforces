#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer a, integer b)
{
    if (2 * a <= b)
        return answer(n * a);

    answer((n / 2) * b + (n % 2) * a);
}

void test_case()
{
    integer n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

