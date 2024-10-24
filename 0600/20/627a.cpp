#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer count(integer s, integer x, unsigned p, unsigned c)
{
    if (~p == 0)
        return c == 0;

    const unsigned bs = (s >> p) & 0x1, bx = (x >> p) & 0x1;

    if (c == 0) {
        if (bs == 0)
            return bx == 0 ? count(s, x, p-1, 0) : 0;
        else
            return bx == 0 ? count(s, x, p-1, 1) : count(s, x, p-1, 0) * 2;
    } else {
        if (bs == 0)
            return bx == 0 ? count(s, x, p-1, 0) : count(s, x, p-1, 1) * 2;
        else
            return bx == 0 ? count(s, x, p-1, 1) : 0;
    }
}

void solve(integer s, integer x)
{
    integer k = count(s, x, 40, 0);
    if (s == x && k != 0)
        k -= 2;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer s, x;
    std::cin >> s >> x;

    solve(s, x);

    return 0;
}
