#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::vector<unsigned>>& c, std::vector<std::vector<unsigned>>& d)
{
    const size_t n = c.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; d[i][j] != 0 && k < n; ++k) {
                const unsigned a = std::min(c[i][k], d[i][j]);
                c[i][k] -= a;
                c[j][k] += a;
                c[j][i] -= a;
                d[i][j] -= a;
            }
        }
    }

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            s += d[i][j];
    }

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> c(n, std::vector<unsigned>(n)), d(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < m; ++i) {
        unsigned x, y, z;
        std::cin >> x >> y >> z;

        c[y-1][x-1] = z;
        d[x-1][y-1] = z;
    }

    solve(c, d);

    return 0;
}

