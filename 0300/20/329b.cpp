#include <iostream>
#include <queue>
#include <string>
#include <vector>

using location_t = std::pair<size_t, size_t>;

constexpr unsigned oo = ~0u;

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

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<location_t> p(2);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == 'T')
                continue;

            if (g[i][j] == 'S')
                p[1] = std::make_pair(i, j);

            if (g[i][j] == 'E')
                p[0] = std::make_pair(i, j);

            if (g[i][j] >= '1' && g[i][j] <= '9')
                p.emplace_back(i, j);
        }
    }

    std::vector<std::vector<unsigned>> d(n, std::vector<unsigned>(m, oo));
    {
        std::queue<location_t> q;

        const auto enqueue = [&](size_t r, size_t c, unsigned v) {
            if (r >= n || c >= m || g[r][c] == 'T')
                return;

            if (d[r][c] == oo) {
                d[r][c] = v;
                q.emplace(r, c);
            }
        };

        enqueue(p[0].first, p[0].second, 0);
        while (!q.empty()) {
            const auto [r, c] = q.front();
            q.pop();

            enqueue(r - 1, c, d[r][c] + 1);
            enqueue(r, c + 1, d[r][c] + 1);
            enqueue(r + 1, c, d[r][c] + 1);
            enqueue(r, c - 1, d[r][c] + 1);
        }
    }

    unsigned k = 0;
    for (size_t i = 2; i < p.size(); ++i) {
        const auto [r, c] = p[i];
        if (d[r][c] <= d[p[1].first][p[1].second])
            k += g[r][c] - '0';
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t r, c;
    std::cin >> r >> c;

    std::vector<std::string> g(r);
    std::cin >> g;

    solve(g);

    return 0;
}
