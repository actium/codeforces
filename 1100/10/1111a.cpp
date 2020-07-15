#include <iostream>
#include <string>

bool vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();
    const size_t m = t.length();

    if (n != m)
        return answer(false);

    for (size_t i = 0; i < n; ++i) {
        if (vowel(s[i]) != vowel(t[i]))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

    solve(s, t);

    return 0;
}

