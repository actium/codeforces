#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned w)
{
    answer(w > 3 && (w - 2) % 2 == 0);
}

int main()
{
    unsigned w;
    std::cin >> w;

    solve(w);

    return 0;
}

