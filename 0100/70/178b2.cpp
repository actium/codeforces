#include <iostream>
#include <utility>
#include <vector>

using pair_t = std::pair<unsigned, unsigned>;

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

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
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

void solve(size_t n, const std::vector<pair_t>& e, const std::vector<pair_t>& p)
{
    const size_t m = e.size(), k = p.size();

    std::vector<unsigned> v(k);

    const auto count = [&](size_t x) {
        DisjointSetUnion dsu(1 + n);
        for (size_t i = 0; i < m; ++i) {
            if (i != x)
                dsu.unite(e[i].first, e[i].second);
        }
        for (size_t i = 0; i < k; ++i) {
            if (dsu.locate(p[i].first) != dsu.locate(p[i].second))
                ++v[i];
        }
    };

    for (size_t i = 0; i < m; ++i)
        count(i);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<pair_t> e(m);
    std::cin >> e;

    size_t k;
    std::cin >> k;

    std::vector<pair_t> p(k);
    std::cin >> p;

    solve(n, e, p);

    return 0;
}
