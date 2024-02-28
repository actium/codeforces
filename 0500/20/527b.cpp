#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x, int y, int z)
{
    std::cout << x << '\n';
    std::cout << y << ' ' << z << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    unsigned r[26][26] = {};

    std::vector<size_t> d;
    for (size_t i = 0; i < n; ++i) {
        const size_t u = s[i] - 'a', v = t[i] - 'a';
        if (u != v) {
            r[u][v] = 1 + i;
            d.push_back(i);
        }
    }

    for (const size_t i : d) {
        const size_t u = s[i] - 'a', v = t[i] - 'a';
        if (r[v][u] != 0)
            return answer(d.size() - 2, 1 + i, r[v][u]);
    }

    for (const size_t i : d) {
        const size_t v = s[i] - 'a';

        for (size_t j = 0; j < 26; ++j) {
            if (j != v && r[j][v] != 0)
                return answer(d.size() - 1, 1 + i, r[j][v]);
        }
    }

    answer(d.size(), -1, -1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
