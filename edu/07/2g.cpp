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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, std::vector<Edge>& e)
{
    std::sort(e.begin(), e.end(), [](const Edge& x, const Edge& y) {
        return x.w < y.w;
    });

    unsigned w = 0;
    {
        ComponentSet cs(1+n);
        for (const Edge& q : e) {
            if (cs[q.b] == cs[q.e])
                continue;

            cs.merge(q.b, q.e);
            w = q.w;
        }
    }
    answer(w);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<Edge> e(k);
    std::cin >> e;

    solve(n, e);

    return 0;
}
