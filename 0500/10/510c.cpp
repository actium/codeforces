#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> g[26], d(26);
    for (size_t i = 1; i < n; ++i) {
        const auto r = std::mismatch(s[i-1].begin(), s[i-1].end(), s[i].begin(), s[i].end());
        if (r.first != s[i-1].end() && r.second == s[i].end())
            return no_answer();

        if (r.first != s[i-1].end() && r.second != s[i].end()) {
            const size_t u = *r.first - 'a', v = *r.second - 'a';
            g[u].push_back(v);
            ++d[v];
        }
    }

    std::vector<unsigned> q;
    for (size_t i = 0; i < 26; ++i) {
        if (d[i] == 0)
            q.push_back(i);
    }

    for (size_t i = 0; i < q.size(); ++i) {
        for (const unsigned x : g[q[i]]) {
            if (--d[x] == 0)
                q.push_back(x);
        }
    }

    if (q.size() != 26)
        return no_answer();

    std::string a;
    for (const unsigned x : q)
        a.push_back('a' + x);

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
