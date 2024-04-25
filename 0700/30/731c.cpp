#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& c, const std::vector<std::pair<unsigned, unsigned>>& e, size_t k)
{
    const size_t n = c.size();

    DisjointSetUnion dsu(n);
    for (const std::pair<unsigned, unsigned>& p : e)
        dsu.unite(p.first - 1, p.second - 1);

    std::vector<std::map<unsigned, unsigned>> f(n);
    for (size_t i = 0; i < n; ++i)
        ++f[dsu.locate(i)][c[i]-1];

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        if (f[i].empty())
            continue;

        unsigned x = 0;
        for (const auto& p : f[i])
            x = std::max(x, p.second);

        s += dsu.size(i) - x;
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(c, e, k);

    return 0;
}
