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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
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

    void unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
    }

private:
    std::vector<int> data_;

}; // class DisjointSetUnion

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& d)
{
    const size_t n = p.size();

    DisjointSetUnion dsu(n);
    for (size_t i = 0; i < n; ++i) {
        if (i >= d[i])
            dsu.unite(i, i - d[i]);

        if (i + d[i] < n)
            dsu.unite(i, i + d[i]);
    }

    for (size_t i = 0; i < n; ++i) {
        if (dsu.locate(i) != dsu.locate(p[i] - 1))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), d(n);
    std::cin >> p >> d;

    solve(p, d);

    return 0;
}
