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

void solve(const std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t n = e.size() + 1;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i)
        s[i].resize(1, i+1);

    DisjointSetUnion dsu(n);
    for (const std::pair<unsigned, unsigned>& q : e) {
        const unsigned v = dsu.locate(q.first-1), w = dsu.locate(q.second-1);
        dsu.unite(v, w);

        const unsigned u = dsu.locate(v);
        s[u].insert(s[u].end(), s[u^v^w].begin(), s[u^v^w].end());
    }

    answer(s[dsu.locate(0)]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n-1);
    std::cin >> e;

    solve(e);

    return 0;
}
