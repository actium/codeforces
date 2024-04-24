#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << "Yes" << '\n';

    std::cout << v.size() << '\n';
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(std::string& s, std::string& t)
{
    const size_t n = s.length();

    std::vector<std::pair<size_t, size_t>> ops;

    std::vector<size_t> p(26, n);
    for (size_t i = 0; i < n; ++i) {
        size_t u = s[i] - 'a', v = t[i] - 'a';
        while (u != v && (p[u] != n || p[v] != n)) {
            if (p[v] != n) {
                ops.emplace_back(p[v], i);
                std::swap(s[p[v]], t[i]);
                p[v] = n;
                v = t[i] - 'a';
            } else {
                ops.emplace_back(i, i);
                std::swap(s[i], t[i]);
                std::swap(u, v);
            }
        }

        if (u != v)
            p[v] = i;
    }

    s == t ? answer(ops) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
