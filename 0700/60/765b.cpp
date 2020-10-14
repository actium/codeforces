#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    char x = 'a';
    for (char c : s) {
        if (c > x)
            return answer(false);

        x = std::max(x, ++c);
    }

    answer(true);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

