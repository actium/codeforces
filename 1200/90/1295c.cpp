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

    size_t x = n, k = 0;
    for (const char c : t) {
        const size_t r = c - 'a';
        if (p[r].empty())
            return no_answer();

        if (x < p[r].back()) {
            x = *std::lower_bound(p[r].begin(), p[r].end(), x + 1);
        } else {
            x = p[r].front();
            ++k;
        }
    }

    answer(k);
}

void test_case()
{
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
