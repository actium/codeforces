#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();
    if (t.length() != n)
        return answer(false);

    for (size_t i = 0; i < n; ++i) {
        if (s[i] != t[n - i - 1])
            return answer(false);
    }

    return answer(true);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

