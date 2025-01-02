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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned check(const std::vector<std::string>& g, size_t r, size_t c, std::vector<std::vector<unsigned>>& s)
{
    if (r == 0 && g[r][c] == 'U')
        return 2;
    if (c == 0 && g[r][c] == 'L')
        return 2;
    if (r + 1 == g.size() && g[r][c] == 'D')
        return 2;
    if (c + 1 == g[0].size() && g[r][c] == 'R')
        return 2;

    if (s[r][c] == 1 || s[r][c] == 3)
        return 3;

    if (s[r][c] == 2)
        return 2;

    s[r][c] = 1;

    if (r > 0 && g[r][c] == 'U')
        s[r][c] = std::max(s[r][c], check(g, r-1, c, s));
    if (c > 0 && g[r][c] == 'L')
        s[r][c] = std::max(s[r][c], check(g, r, c-1, s));
    if (r + 1 < g.size() && g[r][c] == 'D')
        s[r][c] = std::max(s[r][c], check(g, r+1, c, s));
    if (c + 1 < g[0].size() && g[r][c] == 'R')
        s[r][c] = std::max(s[r][c], check(g, r, c+1, s));

    return s[r][c];
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<std::vector<unsigned>> s(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == 0)
                s[i][j] = check(g, i, j, s);
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] != '?')
                k += (s[i][j] != 2);
            else
                k += (i > 0 && s[i-1][j] != 2 || i+1 < n && s[i+1][j] != 2 || j > 0 && s[i][j-1] != 2 || j + 1 < m && s[i][j+1] != 2);
        }
    }

    answer(k);
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
