#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s1, const std::string& s2)
{
    size_t f[256] = { 0 };
    for (const char c : s1)
        ++f[c];

    for (const char c : s2) {
        if (!isspace(c) && f[c]-- == 0)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    solve(s1, s2);

    return 0;
}

