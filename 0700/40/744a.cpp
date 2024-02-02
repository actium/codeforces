#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void paint(const graph_t& g, size_t u, unsigned k, std::vector<unsigned>& v)
{
    v[u] = k;

    for (const size_t x : g[u]) {
        if (v[x] == 0)
            paint(g, x, k, v);
    }
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& r, const std::vector<unsigned>& c)
{
    graph_t g(n);
    for (const std::pair<unsigned, unsigned>& e : r) {
        g[e.first-1].push_back(e.second-1);
        g[e.second-1].push_back(e.first-1);
    }

    std::vector<unsigned> v(n);
    for (const unsigned x : c)
        paint(g, x-1, x, v);

    std::vector<unsigned> f(1+n);
    for (size_t i = 0; i < n; ++i)
        ++f[v[i]];

    if (f[0] != 0) {
        const size_t x = std::max_element(f.begin() + 1, f.end()) - f.begin();
        for (size_t i = 0; i < n; ++i) {
            if (v[i] == 0)
                v[i] = x;
        }
        f[x] += f[0];
    }

    std::vector<unsigned> q(n);
    for (const std::pair<unsigned, unsigned>& e : r)
        ++q[v[e.first-1]-1];

    unsigned k = 0;
    for (const unsigned x : c)
        k += f[x] * (f[x] - 1) / 2 - q[x-1];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> c(k);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(n, r, c);

    return 0;
}
