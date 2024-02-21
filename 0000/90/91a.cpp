#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::vector<size_t> p[26];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'].push_back(i);

    unsigned x = 0, k = 1;
    for (const char c : t) {
        const size_t d = c - 'a';
        if (p[d].empty())
            return no_answer();

        auto it = std::lower_bound(p[d].begin(), p[d].end(), x);
        if (it == p[d].end()) {
            ++k;
            it = std::lower_bound(p[d].begin(), p[d].end(), 0);
        }

        x = *it + 1;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
