#include <iostream>
#include <queue>
#include <vector>

constexpr unsigned oo = ~0u;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

class Graph {
    struct Edge {
        unsigned u;
        unsigned v;
        unsigned c;
    };

public:
    explicit Graph(unsigned vertex_count)
        : nodes_(vertex_count)
        , arrival_timestamps_(vertex_count)
    {}

    unsigned size() const
    {
        return nodes_.size();
    }

    void add_edge(unsigned u, unsigned v, unsigned c)
    {
        nodes_[u].push_back(edges_.size());
        nodes_[v].push_back(edges_.size());
        edges_.push_back({ u, v, c });
    }

    void set_arrival_timestamps(unsigned u, const std::vector<unsigned>& t)
    {
        arrival_timestamps_[u] = t;
    }

    unsigned search(unsigned s, unsigned t) const
    {
        const size_t n = nodes_.size();

        std::vector<unsigned> distances(n, oo);
        std::priority_queue<std::pair<int, unsigned>> queue;

        const auto enqueue = [&](unsigned v, unsigned d) {
            if (d < distances[v]) {
                distances[v] = d;
                queue.emplace(-d, v);
            }
        };

        enqueue(s, 0);
        while (!queue.empty()) {
            auto [d, p] = queue.top();
            queue.pop();

            d = -d;
            if (d != distances[p])
                continue;

            if (p == t)
                break;

            auto it = std::lower_bound(arrival_timestamps_[p].begin(), arrival_timestamps_[p].end(), d);
            while (it != arrival_timestamps_[p].end() && *it == d) {
                ++d;
                ++it;
            }

            for (const unsigned x : nodes_[p]) {
                const Edge& e = edges_[x];
                enqueue(p ^ e.u ^ e.v, d + e.c);
            }
        }

        return distances[t];
    }

private:
    std::vector<std::vector<unsigned>> nodes_;
    std::vector<Edge> edges_;
    std::vector<std::vector<unsigned>> arrival_timestamps_;

}; // class Graph

void solve(const Graph& g)
{
    const unsigned d = g.search(0, g.size()-1);

    d != oo ? answer(d) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    Graph g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b, c;
        std::cin >> a >> b >> c;

        g.add_edge(a-1, b-1, c);
    }

    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        std::vector<unsigned> t(k);
        for (size_t j = 0; j < k; ++j)
            std::cin >> t[j];

        g.set_arrival_timestamps(i, t);
    }

    solve(g);

    return 0;
}
