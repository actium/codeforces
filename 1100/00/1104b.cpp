#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;

    std::string t;
    for (const char c : s) {
        if (t.empty() || t.back() != c) {
            t.push_back(c);
        } else {
            t.pop_back();
            ++k;
        }
    }

    answer(k % 2 != 0);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

