#include <iostream>
#include <utility>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

class ComponentSet {
public:
    explicit ComponentSet(size_t size) :
        roots_(size), sizes_(size, 1)
    {
        for (size_t i = 0; i < size; ++i)
            roots_[i] = i;
    }

    size_t get_root(size_t x)
    {
        size_t rx = x;
        while (rx != roots_[rx])
            rx = roots_[rx];

        while (roots_[x] != rx)
            x = std::exchange(roots_[x], rx);

        return rx;
    }

    size_t get_size(size_t x)
    {
        return sizes_[get_root(x)];
    }

    void merge(size_t x, size_t y)
    {
        size_t rx = get_root(x), ry = get_root(y);
        if (rx == ry)
            return;

        if (sizes_[rx] < sizes_[ry])
            std::swap(rx, ry);

        roots_[ry] = rx;
        sizes_[rx] += sizes_[ry];
    }

private:
    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;

}; // class ComponentSet

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    ComponentSet cs(n);
    for (size_t i = 0; i < n; ++i) {
        for (const size_t j : g[i])
            cs.merge(i, j);
    }

    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() != cs.get_size(i) - 1)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    solve(g);

    return 0;
}
