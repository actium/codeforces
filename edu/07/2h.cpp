#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Edge {
    unsigned b;
    unsigned e;
    unsigned w;
};

std::istream& operator >>(std::istream& input, Edge& v)
{
    return input >> v.b >> v.e >> v.w;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) noexcept;

    void merge(size_t x, size_t y) noexcept;

private:
    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size), sizes_(size, 1)
{
    for (size_t i = 0; i < size; ++i)
        roots_[i] = i;
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
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, std::vector<Edge>& e, integer s)
{
    const size_t m = e.size();

    std::vector<size_t> p(m);
    for (size_t i = 0; i < m; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&e](size_t x, size_t y) {
        return e[x].w > e[y].w;
    });

    ComponentSet cs(1+n);
    for (size_t& i : p) {
        if (cs[e[i].b] != cs[e[i].e]) {
            cs.merge(e[i].b, e[i].e);
            i = m;
        }
    }

    std::vector<size_t> v;
    for (auto it = p.rbegin(); it != p.rend(); ++it) {
        if (*it != m && e[*it].w <= s) {
            v.push_back(*it);
            s -= e[*it].w;
        }
    }

    answer(v);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    integer s;
    std::cin >> s;

    std::vector<Edge> e(m);
    std::cin >> e;

    solve(n, e, s);

    return 0;
}
