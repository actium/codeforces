#include <iostream>
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
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a, size_t k)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> p(1 + n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            p[i+1][j] = p[i][j] + a[i][j];
    }

    std::vector<unsigned> c(m), d(m);
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 0; i < n; ++i) {
            if (a[i][j] == 0)
                continue;

            const unsigned q = p[std::min(i + k, n)][j] - p[i][j];
            if (q > c[j]) {
                c[j] = q;
                d[j] = p[i][j];
            }
        }
    }

    unsigned u = 0, v = 0;
    for (size_t j = 0; j < m; ++j) {
        u += c[j];
        v += d[j];
    }

    answer(u, v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a, k);

    return 0;
}
