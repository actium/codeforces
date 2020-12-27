#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    const unsigned m = n / 2;

    answer(x != m && x != m + 1 || y != m && y != m + 1);
}

int main()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);

    return 0;
}

