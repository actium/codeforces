#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "Mike", "Ann" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    char x = 'z';
    for (const char c : s) {
        answer(x < c);

        x = std::min(x, c);
    }
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

