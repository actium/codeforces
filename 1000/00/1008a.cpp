#include <iostream>
#include <string>

bool vowel(char c)
{
    return c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e';
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (s.back() != 'n' && !vowel(s.back()))
        return answer(false);

    for (size_t i = 0; i < n - 1; ++i) {
        if (s[i] != 'n' && !vowel(s[i]) && !vowel(s[i+1]))
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

