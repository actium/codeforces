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
        roots[locate(y)] = locate(x);
    }

private:
    std::vector<size_t> roots;

}; // class ComponentSet

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<ComponentSet>& cs, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    for (const auto& q : r) {
        unsigned k = 0;
        for (ComponentSet& s : cs)
            k += (s.locate(q.first-1) == s.locate(q.second-1));

        answer(k);
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<ComponentSet> cs(m, ComponentSet(n));
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b, c;
        std::cin >> a >> b >> c;

        cs[c-1].merge(a-1, b-1);
    }

    unsigned q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(cs, r);
///
    return 0;
}
