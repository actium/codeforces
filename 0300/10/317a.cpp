#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer x, integer y, integer m)
{
    if (x > y)
        std::swap(x, y);

    if (y >= m)
        return answer(0);

    if (y <= 0)
        return no_answer();

    integer k = 0;
    if (x < 0) {
        k += std::abs(x) / y + 1;
        x += k * y;
    }

    while (y < m) {
        x += y;
        std::swap(x, y);
        ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer x, y, m;
    std::cin >> x >> y >> m;

    solve(x, y, m);

    return 0;
}
