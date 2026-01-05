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

void answer(const std::vector<edge_t>& v)
{
    for (const edge_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

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

void solve(size_t n, const std::vector<edge_t>& edges)
{
    std::vector<unsigned> d(n);
    for (const edge_t& e : edges) {
        ++d[e.first-1];
        ++d[e.second-1];
    }

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (d[i] > d[x])
            x = i;
    }

    std::vector<edge_t> s;
    {
        DisjointSetUnion dsu(n);
        for (const edge_t& e : edges) {
            if (e.first - 1 == x || e.second - 1 == x) {
                dsu.unite(e.first - 1, e.second - 1);
                s.push_back(e);
            }
        }
        for (const edge_t& e : edges) {
            if (dsu.unite(e.first - 1, e.second - 1))
                s.push_back(e);
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<edge_t> edges(m);
    std::cin >> edges;

    solve(n, edges);

    return 0;
}
