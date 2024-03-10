#include <iostream>
#include <queue>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void fix(std::vector<std::string>& g, size_t i, size_t j, unsigned k)
{
    std::queue<std::pair<size_t, size_t>> q;

    const auto enqueue = [&](size_t r, size_t c) {
        if (r < g.size() && c < g[0].size() && g[r][c] == '.')
            q.emplace(r, c);
    };

    enqueue(i, j);
    while (k != 0) {
        const std::pair<size_t, size_t> p = q.front();
        q.pop();

        if (g[p.first][p.second] == '.') {
            enqueue(p.first - 1, p.second);
            enqueue(p.first, p.second + 1);
            enqueue(p.first + 1, p.second);
            enqueue(p.first, p.second - 1);

            g[p.first][p.second] = '*';
            --k;
        }
    }
}

void solve(std::vector<std::string>& g, unsigned k)
{
    const size_t n = g.size(), m = g[0].length();

    std::pair<size_t, size_t> p;

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                p = std::make_pair(i, j);
                ++s;
            }
        }
    }

    fix(g, p.first, p.second, s - k);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '.')
                g[i][j] = 'X';

            if (g[i][j] == '*')
                g[i][j] = '.';
        }
    }

    answer(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g, k);

    return 0;
}
