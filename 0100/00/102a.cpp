#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::set<size_t>>& g)
{
    const size_t n = g.size();

    unsigned v = -1;
    for (size_t i = 0; i < n; ++i) {
        for (const size_t j : g[i]) {
            for (const size_t k : g[j]) {
                if (g[i].count(k) != 0)
                    v = std::min(v, a[i] + a[j] + a[k]);
            }
        }
    }

    answer(v);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::set<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;
        --u, --v;

        g[u].insert(v);
        g[v].insert(u);
    }

    solve(a, g);

    return 0;
}

