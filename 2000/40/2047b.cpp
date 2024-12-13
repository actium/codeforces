#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    std::vector<std::pair<unsigned, char>> p(26);
    for (size_t i = 0; i < 26; ++i) {
        p[i].first = std::count(s.begin(), s.end(), 'a' + i);
        p[i].second = 'a' + i;
    }

    std::sort(p.begin(), p.end());

    size_t x = 0;
    while (p[x].first == 0)
        ++x;

    s[s.find(p[x].second)] = s[s.find(p.back().second)];

    answer(s);
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
