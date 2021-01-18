#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i] != '?' && s[i] == s[i-1])
            return answer(false);
    }

    if (s.front() == '?' || s.back() == '?')
        return answer(true);

    for (size_t i = 1; i < n; ++i) {
        if (s[i] == s[i-1])
            return answer(true);

        if (s[i] == '?' && s[i-1] == s[i+1])
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

