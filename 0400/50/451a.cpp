#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "Akshat", "Malvika" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned m)
{
    answer(std::min(n, m) % 2 == 0);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

