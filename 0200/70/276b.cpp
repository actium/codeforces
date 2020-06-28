#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "First", "Second" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    size_t f[26] = { 0 };
    for (const char c : s)
        ++f[c - 'a'];

    size_t odd_count = 0;
    for (size_t i = 0; i < 26; ++i) {
        if (f[i] % 2 != 0)
            ++odd_count;
    }

    answer(odd_count > 0 && odd_count % 2 == 0);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

