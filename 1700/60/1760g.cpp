#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<std::pair<size_t, unsigned>>>;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

template <typename F>
void traverse(const graph_t& g, size_t s, F&& f)
{
    std::vector<std::pair<size_t, unsigned>> q;
    std::vector<bool> v(g.size());

    const auto enqueue = [&](size_t u, unsigned x) {
        if (!v[u] && f(u, x)) {
            q.emplace_back(u, x);
            v[u] = true;
        }
    };

    enqueue(s, 0);
    for (size_t i = 0; i < q.size(); ++i) {
        const std::pair<size_t, unsigned> p = q[i];

        for (const std::pair<size_t, unsigned>& e : g[p.first])
            enqueue(e.first, p.second ^ e.second);
    }
}

void solve(const graph_t& g, size_t s, size_t t)
{
    std::vector<unsigned> p;
    {
        traverse(g, s, [&](size_t u, unsigned x) {
            if (u != t) {
                p.push_back(x);
                return true;
            }
            return false;
        });
    }

    bool found = false;
    {
        std::sort(p.begin(), p.end());

        traverse(g, t, [&](size_t u, unsigned x) {
            if (u != t && !found)
                found = std::binary_search(p.begin(), p.end(), x);

            return true;
        });
    }

    answer(found);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v, w;
        std::cin >> u >> v >> w;

        g[u-1].emplace_back(v-1, w);
        g[v-1].emplace_back(u-1, w);
    }

    solve(g, a-1, b-1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
