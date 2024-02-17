#include <iostream>
#include <string>

using integer = unsigned long long;

integer count(integer x)
{
    if (x < 10)
        return x;

    const std::string s = std::to_string(x);
    return (x / 10 - 1) + 9 + (s.front() <= s.back());
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer l, integer r)
{
    answer(count(r) - count(l - 1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}
