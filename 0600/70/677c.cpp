#include <iostream>
#include <string>

constexpr unsigned M = 1000000007;

unsigned code(char c)
{
    if (c >= '0' && c <= '9')
        return 0 + (c - '0');
    if (c >= 'A' && c <= 'Z')
        return 10 + (c - 'A');
    if (c >= 'a' && c <= 'z')
        return 36 + (c - 'a');
    return 62 + (c != '-');
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[64] = {};
    for (unsigned i = 0; i < 64; ++i) {
        for (unsigned j = 0; j < 64; ++j)
            ++f[i & j];
    }

    unsigned k = 1;
    for (const char c : s)
        k = 1ull * k * f[code(c)] % M;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
