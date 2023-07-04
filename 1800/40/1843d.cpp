#include <iostream>
#include <vector>

using integer = unsigned long long;

void traverse(const std::vector<std::vector<size_t>>& g, size_t v, size_t p, std::vector<unsigned>& t)
{
    for (const size_t x : g[v]) {
        if (x != p) {
            traverse(g, x, v, t);
            t[v] += t[x];
        }
    }

    if (t[v] == 0)
        t[v] = 1;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<size_t>>& g, const std::vector<std::pair<size_t, size_t>>& r)
{
    const size_t n = g.size();

    std::vector<unsigned> t(n);
    traverse(g, 0, 0, t);

    for (const auto& q : r) 
        answer(1ull * t[q.first] * t[q.second]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    size_t q;
    std::cin >> q;

    std::vector<std::pair<size_t, size_t>> r(q);
    for (auto& x : r) {
        std::cin >> x.first >> x.second;
        --x.first, --x.second;
    }

    solve(g, r);
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
