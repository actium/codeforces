#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a > b)
        std::swap(a, b);

    answer(b > 0 && b - a < 2);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

