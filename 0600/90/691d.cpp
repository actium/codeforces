#include <algorithm>
#include <iostream>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
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

void solve(const std::vector<unsigned>& p, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = p.size();

    DisjointSetUnion dsu(1+n);
    for (const std::pair<unsigned, unsigned>& q : s)
        dsu.unite(p[q.first-1], p[q.second-1]);

    std::vector<std::vector<unsigned>> q(1+n);
    for (size_t i = 0; i < n; ++i)
        q[dsu.locate(p[i])].push_back(p[i]);

    for (size_t i = 1; i <= n; ++i)
        std::sort(q[i].begin(), q[i].end());

    std::vector<unsigned> v(n);
    for (size_t i = 0; i < n; ++i) {
        const size_t x = dsu.locate(p[i]);
        v[i] = q[x].back();
        q[x].pop_back();
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(p, s);

    return 0;
}
