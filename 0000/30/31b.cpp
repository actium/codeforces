#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No solution" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != '@')
            continue;

        if (!p.empty() && i - p.back() < 3)
            return no_answer();

        p.push_back(i);
    }

    if (p.empty() || p.front() == 0 || p.back() == n-1)
        return no_answer();

    std::string t;
    for (size_t i = 0, j = 0; i < n; ++i) {
        t.push_back(s[i]);

        if (j + 1 < p.size() && i == p[j] + 1) {
            t.push_back(',');
            ++j;
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
