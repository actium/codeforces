#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    integer f[26] = {}, g[26][26] = {};
    for (const char c : s) {
        for (size_t j = 0; j < 26; ++j)
            g[j][c - 'a'] += f[j];

        ++f[c - 'a'];
    }

    integer q = 0;
    for (size_t i = 0; i < 26; ++i) {
        q = std::max(q, f[i]);

        for (size_t j = 0; j < 26; ++j)
            q = std::max(q, g[i][j]);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
