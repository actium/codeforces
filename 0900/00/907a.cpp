#include <algorithm>
#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned v1, unsigned v2, unsigned v3, unsigned v4)
{
    const unsigned s = std::max(v3, v4);
    if (s > 2 * std::min(v3, v4))
        return no_answer();

    const unsigned m = std::max({v2, 2 * v4 + 1, s + 1});
    if (m > 2 * v2)
        return no_answer();

    const unsigned l = std::max({v1, 2 * v4 + 1, m + 1});
    if (l > 2 * v1)
        return no_answer();

    answer(l, m, s);
}

int main()
{
    unsigned v1, v2, v3, v4;
    std::cin >> v1 >> v2 >> v3 >> v4;

    solve(v1, v2, v3, v4);

    return 0;
}

