#include <iostream>
#include <set>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::set<size_t> p[3], q[3];
    for (size_t i = 0; i < n; ++i) {
        p[s[i]-'a'].insert(i);
        q[t[i]-'a'].insert(i);
    }

    const auto f = [](const std::set<size_t> (& s)[3]) {
        size_t x = 3;
        for (size_t i = 0; i < 3; ++i) {
            if (s[i].empty())
                continue;

            if (x == 3 || *s[i].begin() < *s[x].begin())
                x = i;
        }
        return x;
    };

    const auto check = [&](size_t x, size_t y) {
        if (p[y].empty())
            return false;

        if (x == 0 && y == 1 && (p[2].empty() || *p[1].begin() < *p[2].begin()))
            return true;

        if (x == 1 && y == 2 && (p[0].empty() || *p[2].begin() < *p[0].begin()))
            return true;

        return x == y;
    };

    while (p[0].size() + p[1].size() + p[2].size() > 0) {
        const size_t x = f(p), y = f(q);
        if (!check(x, y))
            return answer(false);

        p[y].erase(p[y].begin());
        q[y].erase(q[y].begin());
    }

    answer(true);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
