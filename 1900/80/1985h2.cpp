#include <iostream>
#include <string>
#include <vector>

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

struct Component {
    size_t min_row = oo;
    size_t max_row = 0;
    size_t min_column = oo;
    size_t max_column = 0;
    unsigned size = 0;
};

void extract_component(std::vector<std::string>& g, size_t i, size_t j, Component& c)
{
    if (i < g.size() && j < g[0].size() && g[i][j] == '#') {
        c.min_row = std::min(c.min_row, i);
        c.max_row = std::max(c.max_row, i);
        c.min_column = std::min(c.min_column, j);
        c.max_column = std::max(c.max_column, j);

        ++c.size;

        g[i][j] = '@';

        extract_component(g, i-1, j, c);
        extract_component(g, i, j+1, c);
        extract_component(g, i+1, j, c);
        extract_component(g, i, j-1, c);
    }
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<std::vector<unsigned>> v(n+1, std::vector<unsigned>(m+1));

    const auto update = [&v](size_t lb_r, size_t ub_r, size_t lb_c, size_t ub_c, int d) {
        v[lb_r][lb_c] += d;
        v[lb_r][ub_c+1] -= d;
        v[ub_r+1][lb_c] -= d;
        v[ub_r+1][ub_c+1] += d;
    };

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                update(i, i, 0, m-1, 1);
                update(0, n-1, j, j, 1);
                update(i, i, j, j, -1);
            }

            if (g[i][j] == '#') {
                Component q;
                extract_component(g, i, j, q);

                const size_t lb_r = q.min_row - (q.min_row > 0), ub_r = q.max_row + (q.max_row < n-1);
                const size_t lb_c = q.min_column - (q.min_column > 0), ub_c = q.max_column + (q.max_column < m-1);

                update(lb_r, ub_r, 0, m-1, q.size);
                update(0, n-1, lb_c, ub_c, q.size);
                update(lb_r, ub_r, lb_c, ub_c, -q.size);
            }
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            v[i][j] += (i > 0 ? v[i-1][j] : 0);
            v[i][j] += (j > 0 ? v[i][j-1] : 0);
            v[i][j] -= (i > 0 && j > 0 ? v[i-1][j-1] : 0);

            k = std::max(k, v[i][j]);
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
