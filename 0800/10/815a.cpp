#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<std::string_view, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<std::string_view, size_t>& x : v)
        std::cout << x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g)
{
    const size_t n = g.size(), m = g[0].size();

    unsigned x = ~0u;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            x = std::min(x, g[i][j]);
    }

    std::vector<unsigned> r(n, ~0u);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            r[i] = std::min(r[i], g[i][j] - x);
    }

    std::vector<unsigned> c(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            c[j] = std::max(c[j], g[i][j] - x - r[i]);
    }

    if (n < m) {
        for (size_t i = 0; i < n; ++i)
            r[i] += x;
    } else {
        for (size_t j = 0; j < m; ++j)
            c[j] += x;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (r[i] + c[j] != g[i][j])
                return no_answer();
        }
    }

    std::vector<std::pair<std::string_view, size_t>> v;
    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 0; k < r[i]; ++k)
            v.emplace_back("row", i);
    }
    for (size_t j = 0; j < m; ++j) {
        for (size_t k = 0; k < c[j]; ++k)
            v.emplace_back("col", j);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(m));
    std::cin >> g;

    solve(g);

    return 0;
}
