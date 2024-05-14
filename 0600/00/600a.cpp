#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

size_t check(const std::string_view& s)
{
    for (const char c : s) {
        if (!isdigit(c))
            return 1;
    }
    return s.empty() || s.length() > 1 && s[0] == '0';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<std::string_view> q;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (s[i] == ',' || s[i] == ';') {
            q.emplace_back(s.data() + j, i - j);
            j = i + 1;
        }

        if (i + 1 == n)
            q.emplace_back(s.data() + j, i - j + 1);
    }

    std::string p[2];
    for (const std::string_view& t : q) {
        const size_t x = check(t);
        p[x].push_back(p[x].empty() ? '"' : ',');
        p[x].append(t);
    }

    for (size_t i = 0; i < 2; ++i)
        p[i].push_back(p[i].empty() ? '-' : '"');

    answer(p[0], p[1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
