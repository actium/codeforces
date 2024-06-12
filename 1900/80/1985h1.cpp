#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u;

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

    unsigned size(unsigned x) noexcept
    {
        return -data_[locate(x)];
    }

    unsigned locate(unsigned x) noexcept
    {
        const int rx = data_[x];
        return rx < 0 ? x : locate(rx);
    }

    void unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        save(ru);
        save(rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
    }

    void persist()
    {
        points_.push_back(states_.size());
    }

    void rollback()
    {
        load(points_.back());
        points_.pop_back();
    }

private:
    unsigned size_;

    std::vector<int> data_;

private:
    void save(unsigned x)
    {
        State state;
        state.index = x;
        state.value = data_[x];
        states_.push_back(state);
    }

    void load(size_t t)
    {
        while (states_.size() > t) {
            const State& state = states_.back();
            data_[state.index] = state.value;
            states_.pop_back();
        }
    }

private:
    struct State {
        unsigned index;
        int value;
    };

    std::vector<State> states_;
    std::vector<size_t> points_;

}; // class DisjointSetUnion

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    DisjointSetUnion dsu(n * m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '.')
                continue;

            if (i > 0 && g[i-1][j] == '#')
                dsu.unite(i * m + j, (i - 1) * m + j);
            if (i + 1 < n && g[i+1][j] == '#')
                dsu.unite(i * m + j, (i + 1) * m + j);
            if (j > 0 && g[i][j-1] == '#')
                dsu.unite(i * m + j, i * m + j - 1);
            if (j + 1 < m && g[i][j+1] == '#')
                dsu.unite(i * m + j, i * m + j + 1);
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        dsu.persist();

        for (size_t j = 0; j < m; ++j) {
            if (i > 0 && g[i-1][j] == '#')
                dsu.unite(i * m + j, (i - 1) * m + j);

            if (i + 1 < n && g[i+1][j] == '#')
                dsu.unite(i * m + j, (i + 1) * m + j);

            dsu.unite(i * m + j, i * m);
        }
        k = std::max(k, dsu.size(i * m));

        dsu.rollback();
    }
    for (size_t j = 0; j < m; ++j) {
        dsu.persist();

        for (size_t i = 0; i < n; ++i) {
            if (j > 0 && g[i][j-1] == '#')
                dsu.unite(i * m + j, i * m + j - 1);

            if (j + 1 < m && g[i][j+1] == '#')
                dsu.unite(i * m + j, i * m + j + 1);

            dsu.unite(i * m + j, j);
        }
        k = std::max(k, dsu.size(j));

        dsu.rollback();
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
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
