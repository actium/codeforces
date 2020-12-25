#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    answer(__builtin_popcount(n) == 1);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

