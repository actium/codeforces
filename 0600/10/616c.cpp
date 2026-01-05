#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
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

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].size();

    const auto index = [=](size_t r, size_t c) {
        return r * m + c;
    };

    DisjointSetUnion dsu(index(n, m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] != '.')
                continue;

            for (const int d : { -1, +1 }) {
                if (i + d < n && b[i+d][j] == '.')
                    dsu.unite(index(i, j), index(i + d, j));

                if (j + d < m && b[i][j+d] == '.')
                    dsu.unite(index(i, j), index(i, j + d));
            }
        }
    }

    std::vector<std::string> c(n, std::string(m, '.'));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == '.')
                continue;

            std::set<std::pair<unsigned, unsigned>> s;
            for (const int d : { -1, +1 }) {
                if (i + d < n && b[i+d][j] == '.') {
                    const unsigned x = dsu.locate(index(i + d, j));
                    s.emplace(x, dsu.size(x));
                }
                if (j + d < m && b[i][j+d] == '.') {
                    const unsigned x = dsu.locate(index(i, j + d));
                    s.emplace(x, dsu.size(x));
                }
            }

            unsigned k = 1;
            for (const std::pair<unsigned, unsigned>& e : s)
                k += e.second;

            c[i][j] = '0' + k % 10;
        }
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
