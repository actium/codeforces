#include <iostream>
#include <set>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<size_t> a(n);
    {
        std::set<size_t> q;
        std::vector<bool> v(n);

        const auto enqueue = [&](size_t x) {
            if (!v[x]) {
                q.insert(x);
                v[x] = true;
            }
        };

        enqueue(0);
        for (size_t i = 0; i < n; ++i) {
            a[i] = *q.begin();
            q.erase(q.begin());

            for (const size_t u : g[a[i]])
                enqueue(u);
        }
    }
    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
