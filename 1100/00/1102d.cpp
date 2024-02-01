#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const unsigned k = s.length() / 3;

    const auto index = [](char c) {
        return c - '0';
    };

    unsigned f[3] = {};
    for (const char c : s)
        ++f[index(c)];

    for (auto it = s.begin(); it != s.end(); ++it) {
        if (f[index(*it)] <= k)
            continue;

        for (char c = '0'; c < '2'; ++c) {
            if (*it > c && f[index(c)] < k) {
                --f[index(*it)];
                *it = c;
                ++f[index(*it)];
            }
        }
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (f[index(*it)] <= k)
            continue;

        for (char c = '2'; c > '0'; --c) {
            if (*it < c && f[index(c)] < k) {
                --f[index(*it)];
                *it = c;
                ++f[index(*it)];
            }
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
