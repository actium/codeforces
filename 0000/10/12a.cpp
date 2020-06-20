#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string s[3])
{
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (s[i][j] != s[2-i][2-j])
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    std::string s[3];
    for (size_t i = 0; i < 3; ++i)
        std::cin >> s[i];

    solve(s);

    return 0;
}

