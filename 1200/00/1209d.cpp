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

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : data_(size, -1)
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
        return true;
    }

private:
    std::vector<int> data_;

}; // class DisjointSetUnion

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    unsigned k = 0;

    DisjointSetUnion dsu(1+n);
    for (const std::pair<unsigned, unsigned>& e : p) {
        if (!dsu.unite(e.first, e.second))
            ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> p(k);
    std::cin >> p;

    solve(n, p);

    return 0;
}
