#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const char p[] = "heidi";

    size_t i = 0;
    for (const char c : s) {
        if (i < 5 && c == p[i])
            ++i;
    }

    answer(i == 5);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

