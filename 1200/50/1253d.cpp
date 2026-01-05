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

void answer(unsigned x)
{
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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::vector<size_t> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i] = i;

    DisjointSetUnion dsu(n);
    for (const auto& [u, v] : e) {
        const size_t ru = dsu.locate(u-1), rv = dsu.locate(v-1);
        if (dsu.unite(ru, rv)) {
            b[ru] = std::max(b[ru], b[rv]);
            b[rv] = b[ru];
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t ru = dsu.locate(i);
        if (i == b[ru])
            continue;

        const size_t rv = dsu.locate(i+1);
        if (dsu.unite(ru, rv)) {
            b[ru] = std::max(b[ru], b[rv]);
            b[rv] = b[ru];

            ++k;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e);

    return 0;
}
