#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned s, unsigned t, unsigned u, unsigned v)
{
    answer(s < t && u < v || s > t && u > v);
}

void test_case()
{
    unsigned s, t;
    std::cin >> s >> t;

    unsigned u, v;
    std::cin >> u >> v;

    solve(s, t, u, v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
