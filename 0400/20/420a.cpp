#include <algorithm>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    constexpr char t[] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y' };

    const size_t n = s.length();

    for (size_t i = 0; i < (n + 1) / 2; ++i) {
        if (s[i] != s[n-1-i] || std::find(std::begin(t), std::end(t), s[i]) == std::end(t))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

