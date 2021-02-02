#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    std::string t;
    unsigned u;
    unsigned v;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t;

    if (v.t == "union")
        input >> v.u;

    return input >> v.v;
}

struct ComponentInfo {
    unsigned min;
    unsigned max;
    size_t size;
};

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) noexcept;

    void merge(size_t x, size_t y) noexcept;

    ComponentInfo select(size_t x) noexcept;

private:
    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;

    std::vector<unsigned> mins_;
    std::vector<unsigned> maxs_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size), sizes_(size, 1), mins_(size), maxs_(size)
{
    for (size_t i = 0; i < size; ++i) {
        roots_[i] = i;

        mins_[i] = i;
        maxs_[i] = i;
    }
}

inline size_t ComponentSet::operator [](size_t x) noexcept
{
    size_t root = x;
    while (root != roots_[root])
        root = roots_[root];

    while (roots_[x] != root)
        x = std::exchange(roots_[x], root);

    return root;
}

inline void ComponentSet::merge(size_t x, size_t y) noexcept
{
    size_t rx = operator [](x), ry = operator [](y);
    if (rx == ry)
        return;

    if (sizes_[rx] < sizes_[ry])
        std::swap(rx, ry);

    roots_[ry] = rx;
    sizes_[rx] += sizes_[ry];

    mins_[rx] = std::min(mins_[rx], mins_[ry]);
    maxs_[rx] = std::max(maxs_[rx], maxs_[ry]);
}

inline ComponentInfo ComponentSet::select(size_t x) noexcept
{
    const size_t root = operator [](x);

    return { mins_[root], maxs_[root], sizes_[root] };
}

void answer(const ComponentInfo& v)
{
    std::cout << v.min << ' ' << v.max << ' ' << v.size << '\n';
}

void solve(size_t n, const std::vector<Query>& q)
{
    ComponentSet cs(1+n);

    for (const auto [t, u, v] : q) {
        if (t == "union")
            cs.merge(u, v);
        else
            answer(cs.select(v));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(n, q);

    return 0;
}

