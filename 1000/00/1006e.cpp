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

void no_answer()
{
    std::cout << -1 << '\n';
}

void prepare(const graph_t& g, size_t u, size_t p, std::vector<size_t>& a, std::vector<std::pair<size_t, size_t>>& c)
{
    c[u].first = a.size();

    a.push_back(u);
    for (const size_t v : g[u]) {
        if (v != p)
            prepare(g, v, u, a, c);
    }

    c[u].second = a.size();
}

void solve(const std::vector<unsigned>& p, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = p.size();

    graph_t g(1 + n);
    for (size_t i = 0; i < n; ++i) {
        g[p[i]-1].push_back(1+i);
        g[1+i].push_back(p[i]-1);
    }

    for (size_t i = 0; i <= n; ++i)
        std::sort(g[i].begin(), g[i].end());

    std::vector<size_t> a;
    std::vector<std::pair<size_t, size_t>> c(1 + n);
    prepare(g, 0, 0, a, c);

    for (const std::pair<unsigned, unsigned>& q : r) {
        const std::pair<size_t, size_t>& s = c[q.first-1];
        if (s.second - s.first >= q.second)
            answer(1 + a[s.first + q.second - 1]);
        else
            no_answer();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(p, r);

    return 0;
}
