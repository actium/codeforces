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

class ComponentSet {
public:
    explicit ComponentSet(size_t size)
        : roots(size)
    {
        for (size_t i = 0; i < size; ++i)
            roots[i] = i;
    }

    size_t locate(size_t x)
    {
        size_t rx = x;
        while (rx != roots[rx])
            rx = roots[rx];

        while (roots[x] != rx)
            x = std::exchange(roots[x], rx);

        return rx;
    }

    void merge(size_t x, size_t y)
    {
        const size_t rx = locate(x), ry = locate(y);
        if (rx != ry)
            roots[ry] = rx;
    }

private:
    std::vector<size_t> roots;

}; // class ComponentSet

void answer(const std::vector<edge_t>& v)
{
    std::cout << v.size() << '\n';

    for (const edge_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(size_t n, const std::vector<edge_t>& m, const std::vector<edge_t>& d)
{
    ComponentSet mcs(n), dcs(n);

    for (const edge_t& e : m)
        mcs.merge(e.first-1, e.second-1);

    for (const edge_t& e : d)
        dcs.merge(e.first-1, e.second-1);

    std::vector<edge_t> e;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < i; ++j) {
            if (mcs.locate(i) != mcs.locate(j) && dcs.locate(i) != dcs.locate(j)) {
                e.emplace_back(1+i, 1+j);

                mcs.merge(i, j);
                dcs.merge(i, j);
            }
        }
    }

    answer(e);
}

int main()
{
    size_t n, m1, m2;
    std::cin >> n >> m1 >> m2;

    std::vector<edge_t> m(m1), d(m2);
    std::cin >> m >> d;

    solve(n, m, d);

    return 0;
}
