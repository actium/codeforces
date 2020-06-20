#include <iostream>
#include <string>

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t;
    for (const char c : s) {
        if (!is_vowel(c) || t.empty() || !is_vowel(t.back()))
            t.push_back(c);
    }

    answer(t);
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

