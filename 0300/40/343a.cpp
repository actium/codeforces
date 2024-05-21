#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer a, integer b)
{
    if (a > b)
        std::swap(a, b);

    integer k = 0;
    while (a != 0) {
        k += b / a;
        b %= a;
        std::swap(a, b);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
