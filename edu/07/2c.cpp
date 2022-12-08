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
    unsigned t;
    size_t x;
    size_t y;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t >> v.x >> v.y;
    --v.x;
    --v.y;
    return input;
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

void solve(size_t n, const std::vector<Query>& q)
{
    ComponentSet cs(n);

    std::vector<size_t> nexts(n);
    for (size_t i = 0; i < n; ++i)
        nexts[i] = i + 1;

    const auto next = [&](size_t x) {
        size_t root = nexts[x];
        while (root < n && cs[root] == cs[x])
            root = nexts[root];

        while (nexts[x] != root)
            x = std::exchange(nexts[x], root);

        return root;
    };

    for (const Query& r : q) {
        switch (r.t) {
            case 1:
                cs.merge(r.x, r.y);
                break;
            case 2:
                for (size_t i = next(r.x); i <= r.y; i = next(r.x))
                    cs.merge(r.x, i);
                break;
            case 3:
                answer(cs[r.x] == cs[r.y]);
                break;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<Query> q(k);
    std::cin >> q;

    solve(n, q);

    return 0;
}
