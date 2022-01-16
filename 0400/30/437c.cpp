#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(const std::vector<std::vector<size_t>>& g, std::vector<unsigned>& v)
{
    const size_t n = g.size();

    const auto f = [&](size_t i) {
        unsigned c = 0;
        for (const size_t a : g[i])
            c += v[a];

        return c;
    };

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&v](size_t x, size_t y) { return v[x] > v[y]; });

    unsigned c = 0;
    for (const size_t x : o) {
        c += f(x);
        v[x] = 0;
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> v(n);
    std::cin >> v;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g, v);

    return 0;
}
