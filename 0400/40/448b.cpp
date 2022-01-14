#include <iostream>
#include <string>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, std::string& t)
{
    const size_t n = s.length(), m = t.length();

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (s[i] == t[j] && ++j == m)
            return answer("automaton");
    }

    unsigned f[26] = {};
    for (const char c : s)
        ++f[c-'a'];

    for (const char c : t) {
        if (f[c-'a']-- == 0)
            return answer("need tree");
    }

    for (size_t i = 0; i < 26; ++i) {
        if (f[i] != 0)
            return answer("both");
    }

    answer("array");
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
