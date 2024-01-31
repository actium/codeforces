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

struct Query {
    unsigned r[2];
    unsigned c[2];
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.r[0] >> q.c[0] >> q.r[1] >> q.c[1];
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& g, const std::vector<Query>& r)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<std::vector<unsigned>> ps[2];
    for (size_t i = 0; i < 2; ++i)
        ps[i].resize(n, std::vector<unsigned>(m));

    for (size_t i = 1; i < n; ++i)
        ps[1][i][0] = ps[1][i-1][0] + (g[i-1][0] == '.' && g[i][0] == '.');
    for (size_t j = 1; j < m; ++j)
        ps[0][0][j] = ps[0][0][j-1] + (g[0][j-1] == '.' && g[0][j] == '.');

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            ps[0][i][j] = ps[0][i-1][j] + ps[0][i][j-1] - ps[0][i-1][j-1] + (g[i][j-1] == '.' && g[i][j] == '.');
            ps[1][i][j] = ps[1][i-1][j] + ps[1][i][j-1] - ps[1][i-1][j-1] + (g[i-1][j] == '.' && g[i][j] == '.');
        }
    }

    for (const Query& q : r) {
        unsigned k = ps[0][q.r[1]-1][q.c[1]-1] + ps[1][q.r[1]-1][q.c[1]-1];
        k -= ps[0][q.r[1]-1][q.c[0]-1] + ps[1][q.r[0]-1][q.c[1]-1];
        if (q.r[0] > 1) {
            k -= ps[0][q.r[0]-2][q.c[1]-1];
            k += ps[0][q.r[0]-2][q.c[0]-1];
        }
        if (q.c[0] > 1) {
            k -= ps[1][q.r[1]-1][q.c[0]-2];
            k += ps[1][q.r[0]-1][q.c[0]-2];
        }

        answer(k);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t h, w;
    std::cin >> h >> w;

    std::vector<std::string> g(h);
    std::cin >> g;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(g, r);

    return 0;
}
