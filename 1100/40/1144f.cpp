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

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

bool paint(const graph_t& g, size_t u, unsigned c, std::vector<unsigned>& p)
{
    if (p[u] == 2) {
        p[u] = c;

        for (const size_t v : g[u]) {
            if (!paint(g, v, c^1, p))
                return false;
        }
    }
    return p[u] == c;
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& edges)
{
    const size_t m = edges.size();

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        g[edges[i].first-1].push_back(edges[i].second-1);
        g[edges[i].second-1].push_back(edges[i].first-1);
    }

    std::vector<unsigned> p(n, 2);
    for (size_t i = 0; i < n; ++i) {
        if (p[i] == 2 && !paint(g, i, 0, p))
            return no_answer();
    }

    std::string s(m, '0');
    for (size_t i = 0; i < m; ++i)
        s[i] += p[edges[i].first-1];

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> edges(m);
    std::cin >> edges;

    solve(n, edges);

    return 0;
}
