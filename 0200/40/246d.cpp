#include <iostream>
#include <set>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& edges, const std::vector<unsigned>& c)
{
    std::vector<std::set<unsigned>> g(100001);
    for (const unsigned x : c)
        g[x].insert(x);

    for (const std::pair<unsigned, unsigned>& e : edges) {
        if (c[e.first-1] != c[e.second-1]) {
            g[c[e.first-1]].insert(c[e.second-1]);
            g[c[e.second-1]].insert(c[e.first-1]);
        }
    }

    unsigned x = 1;
    for (unsigned i = 2; i <= 100000; ++i) {
        if (g[i].size() > g[x].size())
            x = i;
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> edges(m);
    std::cin >> edges;

    solve(edges, c);

    return 0;
}