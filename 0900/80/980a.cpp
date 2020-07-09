#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    size_t c[2] = {};
    for (const char x : s)
        ++c[x == 'o'];

    answer(c[1] == 0 || c[0] % c[1] == 0);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

