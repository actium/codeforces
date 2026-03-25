#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
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

struct Edge {
    size_t u;
    size_t v;
    unsigned w;
};

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<Edge> edges;
    {
        unsigned g = p.front();
        for (size_t i = 0; i < n; ++i) {
            g = std::gcd(g, p[i]);
            edges.push_back({ 0, i, g });
        }

        unsigned h = p.back();
        for (size_t i = n; i > 0; --i) {
            h = std::gcd(h, p[i-1]);
            edges.push_back({ i-1, n-1, h });
        }
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs) {
        return lhs.w < rhs.w;
    });

    integer w = 0;
    {
        DisjointSetUnion dsu(n);
        for (const Edge& e : edges) {
            if (dsu.unite(e.u, e.v))
                w += e.w;
        }
    }

    answer(w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
