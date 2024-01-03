#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1 + x.first << ' ' << 1 + x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::vector<size_t> p[2];
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != t[i])
            p[s[i]=='b'].push_back(i);
    }

    if ((p[0].size() + p[1].size()) % 2 == 1)
        return no_answer();

    std::vector<std::pair<size_t, size_t>> c;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 1; j < p[i].size(); j += 2)
            c.emplace_back(p[i][j-1], p[i][j]);
    }

    if (p[0].size() % 2 == 1) {
        c.emplace_back(p[0].back(), p[0].back());
        c.emplace_back(p[0].back(), p[1].back());
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
