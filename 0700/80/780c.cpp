#include <iostream>
#include <queue>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> c(n);
    {
        std::queue<std::pair<size_t, unsigned>> q;

        const auto paint = [&](size_t v, unsigned k, unsigned x) {
            c[v] = k;
            q.emplace(v, x);
        };

        paint(0, 1, 0);
        while (!q.empty()) {
            const std::pair<size_t, unsigned> p = q.front();
            q.pop();

            unsigned k = 1;
            for (const size_t v : g[p.first]) {
                if (c[v] != 0)
                    continue;

                k += (k == c[p.first] || k == p.second);
                k += (k == c[p.first] || k == p.second);

                paint(v, k++, c[p.first]);
            }
        }
    }

    unsigned k = 0;
    for (const unsigned x : c)
        k = std::max(k, x);

    answer(k, c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g);

    return 0;
}
