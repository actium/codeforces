#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "Too weak", "Correct" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    bool uc = false, lc = false, dc = false;
    for (const char c : s) {
        if (isupper(c))
            uc = true;

        if (islower(c))
            lc = true;

        if (isdigit(c))
            dc = true;
    }

    answer(uc && lc && dc && s.length() >= 5);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

