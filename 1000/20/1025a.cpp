#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    size_t f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    for (size_t i = 0; i < 26; ++i) {
        if (f[i] > 1)
            return answer(true);
    }

    answer(s.length() == 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

