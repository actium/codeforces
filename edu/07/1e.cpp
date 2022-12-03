#include <iostream>
#include <utility>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) noexcept;

    void merge(size_t x, size_t y) noexcept;

    template <typename F>
    void traverse(size_t x, F&& f) const noexcept;

private:
    std::vector<size_t> roots_;
    std::vector<std::vector<size_t>> components_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size), components_(size)
{
    for (size_t i = 0; i < size; ++i) {
        roots_[i] = i;
        components_[i].push_back(i);
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

    if (components_[rx].size() < components_[ry].size())
        std::swap(rx, ry);

    components_[rx].insert(components_[rx].end(), components_[ry].begin(), components_[ry].end());
    components_[ry].clear();

    roots_[ry] = rx;
}

template <typename F>
inline void ComponentSet::traverse(size_t x, F&& f) const noexcept
{
    for (const size_t v : components_[x])
        f(v);
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<int, int>>& c, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = c.size();

    std::vector<std::pair<bool, bool>> v(n, std::make_pair(false, false));
    for (const std::pair<unsigned, unsigned>& e : q) {
        if (e.second == 1)
            v[e.first-1].first = true;
        else
            v[e.first-1].second = true;
    }

    std::vector<int> r(n);
    {
        ComponentSet cs(n);

        const auto merge = [&](size_t x, size_t y, int t) {
            size_t cx = cs[x], cy = cs[y];
            if (cx == cy)
                return;

            const size_t c0 = cs[0];
            if (cy == c0)
                std::swap(cx, cy);

            if (cx == c0)
                cs.traverse(cy, [&](size_t i) { r[i] = t; });

            cs.merge(cx, cy);
        };

        for (size_t i = 0; i < n; ++i) {
            if (c[i].first != -1 && !v[i].first)
                merge(i, c[i].first - 1, -1);
            if (c[i].second != -1 && !v[i].second)
                merge(i, c[i].second - 1, -1);
        }

        for (int t = q.size() - 1; t >= 0; --t) {
            const unsigned m1 = q[t].first - 1;
            const unsigned m2 = (q[t].second == 1 ? c[m1].first : c[m1].second) - 1;
            if (m2 != ~0u - 1)
                merge(m1, m2, t);
        }
    }

    r[0] = -1;
    for (size_t i = 0; i < n; ++i)
        answer(r[i]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> c(n);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(c, e);

    return 0;
}
