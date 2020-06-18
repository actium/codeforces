#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const bool f[26])
{
    for (size_t i = 0; i < 26; ++i) {
        if (!f[i])
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    bool f[26] = {};
    for (size_t i = 0; i < n; ++i) {
        char c;
        std::cin >> c;

        f[tolower(c) - 'a'] = true;
    }

    solve(f);

    return 0;
}

