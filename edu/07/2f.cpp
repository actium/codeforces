#include <algorithm>
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

struct Edge {
    unsigned b;
    unsigned e;
    int w;
};

std::istream& operator >>(std::istream& input, Edge& v)
{
    return input >> v.b >> v.e >> v.w;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) noexcept;

    bool merge(size_t x, size_t y) noexcept;

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

inline bool ComponentSet::merge(size_t x, size_t y) noexcept
{
    size_t rx = operator [](x), ry = operator [](y);
    if (rx == ry)
        return false;

    if (sizes_[rx] < sizes_[ry])
        std::swap(rx, ry);

    roots_[ry] = rx;
    sizes_[rx] += sizes_[ry];

    return true;
}

void answer(unsigned v)
{
    std::cout << "YES" << '\n';
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, std::vector<Edge>& e)
{
    const size_t m = e.size();

    std::sort(e.begin(), e.end(), [](const Edge& x, const Edge& y) {
        return x.w < y.w;
    });

    const auto test = [&](size_t x) -> unsigned {
        ComponentSet cs(1+n);
        for (size_t i = x, c = n; i < m; ++i) {
            if (!cs.merge(e[i].b, e[i].e))
                continue;

            if (--c == 1)
                return e[i].w - e[x].w;
        }
        return ~0u;
    };

    unsigned d = ~0u;
    for (size_t i = 0; i < m; ++i)
        d = std::min(d, test(i));

    d == ~0u ? no_answer() : answer(d);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Edge> e(m);
    std::cin >> e;

    solve(n, e);

    return 0;
}

