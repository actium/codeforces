#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& g, const std::string& s)
{
    const size_t n = g.size(), m = g[0].length();

    std::pair<size_t, size_t> b;
    for (size_t i = 0; i < n; ++i) {
        const size_t j = g[i].find('S');
        if (j != std::string::npos) {
            b = { i, j };
            break;
        }
    }

    unsigned k = 0;
    const auto count = [&](const std::string& o) {
        std::pair<int, int> d[256] = {};
        d[o[0]] = { -1,  0 };
        d[o[1]] = {  0, -1 };
        d[o[2]] = {  1,  0 };
        d[o[3]] = {  0,  1 };

        size_t y = b.first, x = b.second;
        for (const char c : s) {
            y += d[c].first;
            x += d[c].second;

            if (y >= n || x >= m || g[y][x] == '#')
                break;

            if (g[y][x] == 'E') {
                ++k;
                break;
            }
        }
    };

    std::string o = "0123";
    do {
        count(o);
    } while (std::next_permutation(o.begin(), o.end()));

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    std::string s;
    std::cin >> s;

    solve(g, s);

    return 0;
}

