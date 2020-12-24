#include <iostream>
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

void solve(const std::vector<std::vector<unsigned>>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<std::pair<size_t, size_t>> r(n, { m, 0 }), c(m, { n, 0 });
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                r[i].first = std::min(r[i].first, j);
                r[i].second = j;
                c[j].first = std::min(c[j].first, i);
                c[j].second = i;
            }
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == 1)
                continue;

            k += (r[i].first < j);
            k += (j < r[i].second);
            k += (c[j].first < i);
            k += (i < c[j].second);
        }
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(m));
    std::cin >> g;

    solve(g);

    return 0;
}

