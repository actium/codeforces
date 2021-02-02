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

    if (v.t != "get")
        input >> v.u;

    return input >> v.v;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) const noexcept;

    void merge(size_t x, size_t y) noexcept;

    void adjust(size_t x, unsigned d) noexcept;

    unsigned select(size_t x) const noexcept;

private:
    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;

    std::vector<int> points_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size), sizes_(size, 1), points_(size)
{
    for (size_t i = 0; i < size; ++i)
        roots_[i] = i;
}

inline size_t ComponentSet::operator [](size_t x) const noexcept
{
    while (x != roots_[x])
        x = roots_[x];

    return x;
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

    points_[ry] -= points_[rx];
}

inline void ComponentSet::adjust(size_t x, unsigned d) noexcept
{
    const size_t root = operator [](x);

    points_[root] += d;
}

inline unsigned ComponentSet::select(size_t x) const noexcept
{
    int points = points_[x];

    while (x != roots_[x]) {
        x = roots_[x];
        points += points_[x];
    }

    return points;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<Query>& q)
{
    ComponentSet cs(1+n);

    for (const auto [t, u, v] : q) {
        if (t == "join")
            cs.merge(u, v);

        if (t == "add")
            cs.adjust(u, v);

        if (t == "get")
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

