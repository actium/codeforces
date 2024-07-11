#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[2] = { "First", "Second" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned r)
{
    answer(a < 2 * r || b < 2 * r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b, r;
    std::cin >> a >> b >> r;

    solve(a, b, r);

    return 0;
}
