#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << '-' << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p[10];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'0'].push_back(i);

    std::vector<std::vector<size_t>> c(1);
    for (size_t i = 0; i < 10; ++i) {
        if (p[i].empty())
            continue;

        if (c.back().empty() || c.back().back() < p[i].front()) {
            c.back().insert(c.back().end(), p[i].begin(), p[i].end());
            continue;
        }

        const auto it = std::lower_bound(p[i].begin(), p[i].end(), c.back().back());
        c.back().insert(c.back().end(), it, p[i].end());
        c.emplace_back(p[i].begin(), it);
    }

    if (c.size() > 2)
        return no_answer();

    std::string t(n, '2');
    for (const size_t i : c[0])
        t[i] = '1';

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
