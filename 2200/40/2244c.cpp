#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& p, size_t x, size_t y)
{
    const size_t n = p.size();

    DisjointSetUnion dsu(n);
    for (size_t i = 0; i < n; ++i) {
        if (i + x < n)
            dsu.unite(i, i + x);

        if (i + y < n)
            dsu.unite(i, i + y);
    }

    for (size_t i = 0; i < n; ++i) {
        if (dsu.locate(p[i]-1) != dsu.locate(i))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, x, y;
    std::cin >> n >> x >> y;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
