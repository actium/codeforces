#include <iostream>
#include <queue>
#include <vector>

using point_t = std::pair<short, short>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const point_t& x)
{
    std::cout << x.first << ' ' << x.second << '\n';
}

void solve(size_t n, size_t m, const std::vector<point_t>& p)
{
    std::vector<std::vector<unsigned>> t(1 + n, std::vector<unsigned>(1 + m, ~0u));

    std::queue<point_t> q;

    const auto enqueue = [&](short r, short c, unsigned d) {
        if (t[r][c] == ~0u) {
            t[r][c] = d;
            q.emplace(r, c);
        }
    };

    for (const point_t& x : p)
        enqueue(x.first, x.second, 0);

    while (!q.empty()) {
        const point_t p = q.front();
        q.pop();

        const unsigned u = t[p.first][p.second] + 1;

        if (p.first > 1)
            enqueue(p.first - 1, p.second, u);

        if (p.first < n)
            enqueue(p.first + 1, p.second, u);

        if (p.second > 1)
            enqueue(p.first, p.second - 1, u);

        if (p.second < m)
            enqueue(p.first, p.second + 1, u);
    }

    point_t x = { 1, 1 };
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (t[i][j] > t[x.first][x.second])
                x = std::make_pair(i, j);
        }
    }

    answer(x);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<point_t> p(k);
    std::cin >> p;

    solve(n, m, p);

    return 0;
}
