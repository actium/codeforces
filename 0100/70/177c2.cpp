#include <iostream>
#include <utility>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;

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

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

    unsigned size(unsigned x) noexcept
    {
        return -data_[locate(x)];
    }

    unsigned locate(unsigned x) noexcept
    {
        unsigned rx = x;
        while (data_[rx] >= 0)
            rx = data_[rx];

        while (data_[x] >= 0)
            x = std::exchange(data_[x], rx);

        return rx;
    }

    bool unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return false;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
        --size_;

        return true;
    }

private:
    unsigned size_;

    std::vector<int> data_;

}; // class DisjointSetUnion

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<edge_t>& p, const std::vector<edge_t>& r)
{
    DisjointSetUnion dsu(n);
    for (const edge_t& e : p)
        dsu.unite(e.first - 1, e.second - 1);

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < n; ++i)
        s[dsu.locate(i)] = dsu.size(i);

    for (const edge_t& e : r) {
        if (dsu.locate(e.first - 1) == dsu.locate(e.second - 1))
            s[dsu.locate(e.first - 1)] = 0;
    }

    unsigned v = 0;
    for (size_t i = 0; i < n; ++i)
        v = std::max(v, s[i]);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<edge_t> p(k);
    std::cin >> p;

    size_t m;
    std::cin >> m;

    std::vector<edge_t> r(m);
    std::cin >> r;

    solve(n, p, r);

    return 0;
}
