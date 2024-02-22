#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<char, char>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<char, char>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    char x[256] = {};
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            x[s[i]] = t[i];
            x[t[i]] = s[i];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == t[i] && x[s[i]] != 0)
            return no_answer();

        if (s[i] != t[i] && (x[s[i]] != t[i] || x[t[i]] != s[i]))
            return no_answer();
    }

    std::vector<std::pair<char, char>> r;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (x[c] != 0) {
            r.emplace_back(c, x[c]);
            x[x[c]] = 0;
        }
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
