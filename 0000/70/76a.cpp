#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size)
        : roots_(size), ranks_(size), size_(size)
    {
        for (size_t i = 0; i < size_; ++i)
            roots_[i] = i;
    }

    size_t resolve(size_t index)
    {
        size_t root = index;
        while (root != roots_[root])
            root = roots_[root];

        while (roots_[index] != root)
            index = std::exchange(roots_[index], root);

        return root;
    }

    bool merge(size_t u, size_t v)
    {
        size_t ru = resolve(u), rv = resolve(v);
        if (ru == rv)
            return false;

        if (ranks_[ru] < ranks_[rv])
            std::swap(ru, rv);

        roots_[rv] = ru;

        if (ranks_[ru] == ranks_[rv])
            ++ranks_[ru];

        --size_;
        return true;
    }

    size_t size() const
    {
        return size_;
    }

private:
    std::vector<size_t> roots_;
    std::vector<size_t> ranks_;
    size_t size_;

}; // class ComponentSet

struct Node {
    size_t v;
    integer s;
};

using graph_t = std::vector<std::vector<Node>>;

void traverse(const graph_t& g, size_t u, size_t p, std::vector<Node>& t)
{
    for (const Node& x : g[u]) {
        if (x.v == p)
            continue;

        t[x.v].v = u;
        t[x.v].s = x.s;
        traverse(g, x.v, u, t);
    }
}

void drop_node(graph_t& g, size_t u, size_t v)
{
    for (Node& x : g[u]) {
        if (x.v == v) {
            std::swap(x, g[u].back());
            g[u].pop_back();
            break;
        }
    }
}

struct Edge {
    size_t u;
    size_t v;

    integer g;
    integer s;
};

void solve(size_t n, std::vector<Edge>& e)
{
    integer w = oo;

    std::sort(e.begin(), e.end(), [](const Edge& x, const Edge& y) {
        return std::make_pair(x.g, x.s) < std::make_pair(y.g, y.s);
    });

    ComponentSet cs(n);

    graph_t g(n);
    for (const Edge& q : e) {
        if (q.u == q.v)
            continue;

        if (cs.merge(q.u, q.v)) {
            g[q.u].push_back({ q.v, q.s });
            g[q.v].push_back({ q.u, q.s });
        } else {
            std::vector<Node> t(n);
            traverse(g, q.u, q.u, t);

            std::pair<integer, size_t> ub = { 0, n };
            for (size_t x = q.v; x != q.u; x = t[x].v) {
                if (ub.first < t[x].s) {
                    ub.first = t[x].s;
                    ub.second = x;
                }
            }

            if (ub.first > q.s) {
                drop_node(g, t[ub.second].v, ub.second);
                drop_node(g, ub.second, t[ub.second].v);

                g[q.u].push_back({ q.v, q.s });
                g[q.v].push_back({ q.u, q.s });
            }
        }

        if (cs.size() == 1) {
            integer s = 0;
            for (size_t i = 0; i < n; ++i) {
                for (const Node& x : g[i])
                    s = std::max(s, x.s);
            }

            w = std::min(w, q.g + s);
        }
    }

    if (w != oo)
        return answer(w);

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned g, s;
    std::cin >> g >> s;

    std::vector<Edge> e(m);
    for (size_t i = 0; i < m; ++i) {
        std::cin >> e[i].u >> e[i].v >> e[i].g >> e[i].s;

        --e[i].u;
        --e[i].v;

        e[i].g *= g;
        e[i].s *= s;
    }

    solve(n, e);

    return 0;
}
