#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << '/' << y << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g, size_t n, size_t p)
{
    const size_t r = g.size(), c = g[0].size();

    std::vector<std::pair<size_t, size_t>> x(1+n);
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            if (g[i][j] != 0)
                x[g[i][j]] = { i, j };
        }
    }

    std::set<unsigned> s;

    const auto check = [&](size_t i, size_t j, size_t d) {
        if (g[i][j] != 0 && g[i][j] + d <= n)
            s.insert(g[i][j] + d);
    };

    for (size_t i = 1; i <= p; ++i) {
        const size_t d = p - i;

        if (x[i].first != 0)
            check(x[i].first-1, x[i].second, d);

        if (x[i].first + 1 < r)
            check(x[i].first+1, x[i].second, d);

        if (x[i].second != 0)
            check(x[i].first, x[i].second - 1, d);

        if (x[i].second + 1 < c)
            check(x[i].first, x[i].second + 1, d);
    }

    answer(s.size(), n - 1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t r, c, n, p;
    std::cin >> r >> c >> n >> p;

    std::vector<std::vector<unsigned>> g(r, std::vector<unsigned>(c));
    std::cin >> g;

    solve(g, n, p);

    return 0;
}
