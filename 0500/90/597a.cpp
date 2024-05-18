#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer k, integer a, integer b)
{
    if (a < 0 && b < 0) {
        const integer c = b;
        b = -a;
        a = -c;
    }

    answer(b / k - (a > 0 ? a - 1 : a - k) / k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer k, a, b;
    std::cin >> k >> a >> b;

    solve(k, a, b);

    return 0;
}
