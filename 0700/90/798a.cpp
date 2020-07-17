#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i])
            ++k;
    }

    answer(k == 1 || (k == 0 && n % 2 == 1));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

