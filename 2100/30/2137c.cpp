#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer a, integer b)
{
    if (a * b % 2 == 1)
        return answer(a * b + 1);

    if (b % 2 == 0 && a * b / 2 % 2 == 0)
        return answer(a * b / 2 + 2);

    no_answer();
}

void test_case()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);
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
