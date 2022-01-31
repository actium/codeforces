#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const std::string p = "CODEFORCES";

    const size_t n = s.length();
    if (n < p.length())
        return answer(false);

    auto i = s.cbegin();
    for (auto it = p.cbegin(); *i == *it; ++i, ++it);

    auto j = s.crbegin();
    for (auto it = p.crbegin(); *j == *it; ++j, ++it);

    answer(std::distance(s.cbegin(), i) + std::distance(s.crbegin(), j) >= p.length());
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
