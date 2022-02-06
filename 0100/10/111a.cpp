#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    for (const integer x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer x, integer y)
{
    if (y < n)
        return no_answer();

    std::vector<integer> a(n, 1);
    a.back() = y - (n - 1);
    if (n - 1 + a.back() * a.back() < x)
        return no_answer();

    answer(a);
}

int main()
{
    integer n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);

    return 0;
}
