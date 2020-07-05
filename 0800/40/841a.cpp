#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t k)
{
    size_t f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    for (size_t i = 0; i < 26; ++i) {
        if (f[i] > k)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

