#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned M = 1'000'000'007;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::pair<unsigned long long, unsigned>& x)
{
    std::cout << x.first << ' ' << x.second << '\n';
}

void traverse_1(const graph_t& g, size_t u, std::vector<bool>& v, std::vector<size_t>& p)
{
    v[u] = true;

    for (const size_t x : g[u]) {
        if (!v[x])
            traverse_1(g, x, v, p);
    }

    p.push_back(u);
}

void traverse_2(const graph_t& g, size_t u, std::vector<unsigned>& cs, std::vector<size_t>& v)
{
    v.push_back(u);

    for (const size_t x : g[u]) {
        if (cs[x] == 0) {
            cs[x] = cs[u];
            traverse_2(g, x, cs, v);
        }
    }
}

void solve(const graph_t& g, const graph_t& h, const std::vector<unsigned>& c)
{
    const size_t n = g.size();

    std::vector<size_t> p;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (!v[i])
                traverse_1(g, i, v, p);
        }
    }

    std::vector<std::vector<size_t>> s;
    {
        std::vector<unsigned> cs(n);
        for (auto it = p.rbegin(); it != p.rend(); ++it) {
            if (cs[*it] == 0) {
                s.emplace_back();
                cs[*it] = s.size();
                traverse_2(h, *it, cs, s.back());
            }
        }
    }

    std::pair<unsigned long long, unsigned> r = { 0, 1 };
    for (const std::vector<size_t>& v : s) {
        std::pair<unsigned, unsigned> x = { ~0u, 0 };
        for (const size_t u : v) {
            if (c[u] < x.first)
                x = { c[u], 0 };

            if (c[u] == x.first)
                ++x.second;
        }

        r.first += x.first;
        r.second = 1ull * r.second * x.second % M;
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    size_t m;
    std::cin >> m;

    graph_t g(n), h(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        h[v-1].push_back(u-1);
    }

    solve(g, h, c);

    return 0;
}
