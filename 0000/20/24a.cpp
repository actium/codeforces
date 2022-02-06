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

unsigned traverse(const std::vector<std::vector<std::pair<size_t, unsigned>>>& g, size_t u, size_t p)
{
    if (u == 0 && p != 0)
        return 0;

    unsigned c = ~0u;
    for (const std::pair<size_t, unsigned>& x : g[u]) {
        if (x.first != p)
            c = std::min(c, traverse(g, x.first, u) + x.second);
    }
    return c;
}

void solve(const std::vector<std::vector<unsigned>>& r)
{
    const size_t n = r.size();

    std::vector<std::vector<std::pair<size_t, unsigned>>> g(n);
    for (const std::vector<unsigned>& x : r) {
        const size_t u = x[0] - 1, v = x[1] - 1;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, x[2]);
    }

    answer(traverse(g, 0, 0));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> r(n, std::vector<unsigned>(3));
    std::cin >> r;

    solve(r);

    return 0;
}
