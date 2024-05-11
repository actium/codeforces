#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<std::pair<unsigned, size_t>> b(n);
    for (size_t i = 1; i < n; ++i) {
        b[i].first = b[i-1].first + (s[i-1] == '(' ? 1 : -1);
        b[i].second = i;
    }

    std::sort(b.begin(), b.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second > rhs.second;
    });

    std::string t(n, ' ');
    for (size_t i = 0; i < n; ++i)
        t[i] = s[b[i].second];

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
