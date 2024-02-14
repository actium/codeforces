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

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    DisjointSetUnion dsu(n);
    for (const std::pair<unsigned, unsigned>& p : e) {
        dsu.unite(p.first - 1, p.second -1);

        if (dsu.size(p.first - 1) > 3)
            return no_answer();
    }

    std::vector<unsigned> d[3];
    for (size_t i = 0; i < n; ++i)
        d[dsu.size(i)-1].push_back(i);

    if (d[1].size() / 2 > d[0].size())
        return no_answer();

    std::vector<unsigned> c(n);
    for (size_t i = 1, k = 0; i < 3; ++i) {
        for (const size_t x : d[i]) {
            const unsigned u = dsu.locate(x);
            c[x] = (c[u] != 0 ? c[u] : ++k);
        }
    }

    std::vector<std::vector<unsigned>> t(n / 3);
    for (size_t i = 0; i < n; ++i) {
        if (c[i] != 0)
            t[c[i]-1].push_back(i + 1);
    }
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (c[i] != 0)
            continue;

        while (t[j].size() == 3)
            ++j;

        t[j].push_back(i + 1);
    }

    answer(t);
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
