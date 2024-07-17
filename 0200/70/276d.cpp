#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer l, integer r)
{
    if (l == r)
        return answer(0);

    integer x = 1ull << 63;
    while ((l & x) == (r & x))
        x >>= 1;

    answer(x | x - 1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}
