#include <iostream>
#include <string>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p[26];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'].push_back(i);

    for (size_t i = 1; i < n-1; ++i) {
        if (p[s[i]-'a'].front() < i || p[s[i]-'a'].back() > i)
            return answer(true);
    }

    answer(false);
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
