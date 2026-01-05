#include <iostream>
#include <utility>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;

constexpr int oo = ~0u >> 1;

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

void solve(const std::vector<unsigned>& w, const std::vector<unsigned>& b, const std::vector<edge_t>& e, unsigned s)
{
    const size_t n = w.size();

    DisjointSetUnion dsu(n);
    for (const auto& [u, v] : e)
        dsu.unite(u-1, v-1);

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < n; ++i)
        g[dsu.locate(i)].push_back(i);

    std::vector<int> dp(1 + s, -oo);
    dp[0] = 0;
    for (const std::vector<size_t>& a : g) {
        std::vector<int> ndp = dp;

        const auto update = [&](unsigned w, unsigned b) {
            for (unsigned i = s; i >= w; --i)
                ndp[i] = std::max<int>(ndp[i], dp[i-w] + b);
        };

        unsigned cw = 0, cb = 0;
        for (const size_t u : a) {
            update(w[u], b[u]);
            cw += w[u];
            cb += b[u];
        }

        if (cw != 0)
            update(cw, cb);

        std::swap(dp, ndp);
    }

    int x = 0;
    for (unsigned i = 1; i <= s; ++i)
        x = std::max(x, dp[i]);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> w(n), b(n);
    std::cin >> w >> b;

    std::vector<edge_t> e(m);
    std::cin >> e;

    solve(w, b, e, s);

    return 0;
}
