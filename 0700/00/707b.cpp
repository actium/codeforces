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

using road_t = std::pair<size_t, unsigned>;

void solve(const std::vector<std::vector<road_t>>& g, const std::vector<unsigned>& a)
{
    constexpr unsigned oo = ~0u;

    std::set<unsigned> s(a.cbegin(), a.cend());

    unsigned d = oo;
    for (const unsigned x : a) {
        for (const auto& r : g[x]) {
            if (s.count(r.first) == 0)
                d = std::min(d, r.second);
        }
    }

    answer(d < oo ? d : -1);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<road_t>> g(1+n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v, l;
        std::cin >> u >> v >> l;

        g[u].emplace_back(v, l);
        g[v].emplace_back(u, l);
    }

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(g, a);

    return 0;
}

