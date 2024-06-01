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

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::pair<size_t, size_t> s, t;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == 'S')
                s = { i, j };

            if (g[i][j] == 'T')
                t = { i, j };
        }
    }

    const auto check_h = [&](size_t r, size_t lc, size_t uc) {
        if (lc > uc)
            std::swap(lc, uc);

        for (size_t i = lc; i <= uc; ++i) {
            if (g[r][i] == '*')
                return false;
        }
        return true;
    };

    const auto check_v = [&](size_t c, size_t lr, size_t ur) {
        if (lr > ur)
            std::swap(lr, ur);

        for (size_t i = lr; i <= ur; ++i) {
            if (g[i][c] == '*')
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < n; ++i) {
        if (check_h(i, s.second, t.second) && check_v(s.second, i, s.first) && check_v(t.second, i, t.first))
            return answer(true);
    }

    for (size_t j = 0; j < m; ++j) {
        if (check_v(j, s.first, t.first) && check_h(s.first, j, s.second) && check_h(t.first, j, t.second))
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}
