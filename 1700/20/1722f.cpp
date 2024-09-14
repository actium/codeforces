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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

struct Option {
    int dr;
    int dc;
    std::pair<int, int> t[11];
};

constexpr Option options[4] = {
    {
        -1, -1,
        { { -2, -1 }, { -2, 0 }, { -2, 1 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 1, -2 }, { 0, -2 }, { -1, -2 } }
    },
    {
        -1, 0,
        { { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 1, -2 }, { 0, -2 }, { -1, -2 }, { -2, -2 }, { -2, -1 }, { -2, 0 } }
    },
    {
        0, -1,
        { { 0, -2 }, { -1, -2 }, { -2, -2 }, { -2, -1 }, { -2, 0 }, { -2, 1 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 } }
    },
    {
        0, 0,
        { { 1, 0 }, { 1, -1 }, { 1, -2 }, { 0, -2 }, { -1, -2 }, { -2, -2 }, { -2, -1 }, { -2, 0 }, { -2, 1 }, { -1, 1 }, { 0, 1 } }
    },
};

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    const auto v = [&](size_t r, size_t c) {
        return r < n && c < m ? g[r][c] == '*' : false;
    };

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            const unsigned k = v(i-1, j-1) + v(i-1, j) + v(i, j-1) + v(i, j);
            if (k != 3)
                continue;

            for (const Option& option : options) {
                if (v(i + option.dr, j + option.dc))
                    continue;

                for (const auto& [dr, dc] : option.t) {
                    if (i + dr < n && j + dc < m && g[i+dr][j+dc] == '*')
                        return answer(false);
                }
            }

            g[i-1][j-1] = '.';
            g[i-1][j-0] = '.';
            g[i-0][j-1] = '.';
            g[i-0][j-0] = '.';
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '*')
                return answer(false);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
