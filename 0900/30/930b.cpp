#include <iostream>
#include <string>
#include <vector>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto index = [&](size_t x) {
        return s[x % n] - 'a';
    };

    std::vector<size_t> p[26];
    for (size_t i = 0; i < n; ++i)
        p[index(i)].push_back(i);

    unsigned b[26] = {};
    for (size_t d = 1; d < n; ++d) {
        for (size_t i = 0; i < 26; ++i) {
            unsigned f[26] = {};
            for (const size_t x : p[i])
                ++f[index(x + d)];

            unsigned k = 0;
            for (size_t i = 0; i < 26; ++i)
                k += (f[i] == 1);

            b[i] = std::max(b[i], k);
        }
    }

    unsigned v = 0;
    for (size_t i = 0; i < 26; ++i)
        v += b[i];

    answer(v / double(n));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
