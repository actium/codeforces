#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer b, integer c)
{
    if (c >= n)
        return answer(n);

    if (b == 0 && c + 2 >= n)
        return answer(n - (c < n));

    if (b == 0)
        return no_answer();

    answer(n - (n - c - 1) / b - 1);
}

void test_case()
{
    integer n, b, c;
    std::cin >> n >> b >> c;

    solve(n, b, c);
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
