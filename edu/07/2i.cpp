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
    unsigned a;
    unsigned b;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.t >> v.a >> v.b;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    std::pair<size_t, unsigned> operator [](size_t x) noexcept;

    void merge(size_t x, size_t y) noexcept;

private:
    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;
    std::vector<unsigned> colors_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size), sizes_(size, 1), colors_(size)
{
    for (size_t i = 0; i < size; ++i)
        roots_[i] = i;
}

inline std::pair<size_t, unsigned> ComponentSet::operator [](size_t x) noexcept
{
    if (roots_[x] != x) {
        const auto r =(*this)[roots_[x]];
        roots_[x] = r.first;
        colors_[x] = (colors_[x] + r.second) % 2;
    }
    return std::make_pair(roots_[x], colors_[x]);
}

inline void ComponentSet::merge(size_t x, size_t y) noexcept
{
    auto rx = operator [](x), ry = operator [](y);
    if (rx.first == ry.first)
        return;

    if (sizes_[rx.first] < sizes_[ry.first])
        std::swap(rx, ry);

    roots_[ry.first] = rx.first;
    sizes_[rx.first] += sizes_[ry.first];
    colors_[ry.first] = (rx.second + ry.second + 1) % 2;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, const std::vector<Query>& q)
{
    unsigned shift = 0;

    const auto index = [&](unsigned x) {
        return (x - 1 + shift) % n;
    };

    ComponentSet cs(n);
    for (const Query& r : q) {
        if (r.t == 0) {
            cs.merge(index(r.a), index(r.b));
            continue;
        }

        if (cs[index(r.a)].second == cs[index(r.b)].second) {
            answer(true);
            ++shift;
        } else {
            answer(false);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(n, q);

    return 0;
}
