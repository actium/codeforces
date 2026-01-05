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

    unsigned size() const noexcept
    {
        return size_;
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

    void unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
        --size_;
    }

private:
    unsigned size_;

    std::vector<int> data_;

}; // class DisjointSetUnion

void solve(size_t n, const std::vector<edge_t>& s1, const std::vector<edge_t>& s2)
{
    DisjointSetUnion g(1+n);
    for (const edge_t& e : s2)
        g.unite(e.first, e.second);

    unsigned k = 0;

    DisjointSetUnion f(1+n);
    for (const edge_t& e : s1) {
        if (g.locate(e.first) == g.locate(e.second))
            f.unite(e.first, e.second);
        else
            ++k;
    }

    answer(k + f.size() - g.size());
}

void test_case()
{
    size_t n, m1, m2;
    std::cin >> n >> m1 >> m2;

    std::vector<edge_t> s1(m1), s2(m2);
    std::cin >> s1 >> s2;

    solve(n, s1, s2);
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
