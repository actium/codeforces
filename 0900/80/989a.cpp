#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n-1; ++i) {
        if (s[i-1] == '.' || s[i] == '.' || s[i+1] == '.')
            continue;

        if (s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1])
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

