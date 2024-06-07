#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

bool is_leap(unsigned x)
{
    return x % 400 == 0 || x % 4 == 0 && x % 100 != 0;
}

void solve(unsigned y)
{
    unsigned x = y + 1, d = 365 + is_leap(y);
    while (is_leap(x) != is_leap(y) || d % 7 != 0)
        d += 365 + is_leap(x++);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned y;
    std::cin >> y;

    solve(y);

    return 0;
}
