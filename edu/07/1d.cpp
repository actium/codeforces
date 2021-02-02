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
    return input >> v.t >> v.u >> v.v;
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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, std::vector<Query>& q)
{
    ComponentSet cs(1+n);

    std::vector<bool> r;
    for (auto it = q.rbegin(); it != q.rend(); ++it) {
        if (it->t == "ask")
            r.push_back(cs[it->u] == cs[it->v]);
        else
            cs.merge(it->u, it->v);
    }

    for (auto it = r.rbegin(); it != r.rend(); ++it)
        answer(*it);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;
    }

    std::vector<Query> q(k);
    std::cin >> q;

    solve(n, q);

    return 0;
}

