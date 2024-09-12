#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve()
{
    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}
