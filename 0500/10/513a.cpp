#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "First", "Second" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n1, unsigned n2, unsigned k1, unsigned k2)
{
    answer(n1 <= n2);
}

int main()
{
    unsigned n1, n2, k1, k2;
    std::cin >> n1 >> n2 >> k1 >> k2;

    solve(n1, n2, k1, k2);

    return 0;
}

