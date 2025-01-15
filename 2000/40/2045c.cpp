#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    size_t p[26] = {};
    for (size_t i = 0; i + 1 < m; ++i)
        p[t[i]-'a'] = i + 1;

    std::pair<size_t, size_t> v = { n, 0 };
    for (size_t i = 1; i < n; ++i) {
        const size_t q = p[s[i]-'a'];
        if (q > 0 && q < m && i + m - q < v.first + m - v.second)
            v = std::make_pair(i, q);
    }

    if (v.first == n)
        return no_answer();

    answer(s.substr(0, v.first + 1) + t.substr(v.second));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
