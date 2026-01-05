#include <algorithm>
#include <iostream>
#include <string>

size_t count_vowels(const std::string& s)
{
    return std::count_if(s.cbegin(), s.cend(), [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; });
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s1, const std::string& s2, const std::string& s3)
{
    const size_t c1 = count_vowels(s1);
    const size_t c2 = count_vowels(s2);
    const size_t c3 = count_vowels(s3);

    answer(c1 == 5 && c2 == 7 && c3 == 5);
}

int main()
{
    std::string s1, s2, s3;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    std::getline(std::cin, s3);

    solve(s1, s2, s3);

    return 0;
}

