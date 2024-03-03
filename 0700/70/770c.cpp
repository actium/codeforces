#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool traverse(const std::vector<std::vector<unsigned>>& g, size_t u, std::vector<unsigned>& c, std::vector<size_t>& p)
{
    if (c[u] != 0)
        return c[u] == 2;

    c[u] = 1;
    for (const unsigned x : g[u]) {
        if (!traverse(g, x - 1, c, p))
            return false;
    }
    c[u] = 2;

    p.push_back(u);
    return true;
}

void solve(const std::vector<std::vector<unsigned>>& g, const std::vector<unsigned>& r)
{
    const size_t n = g.size();

    std::vector<size_t> p;

    std::vector<unsigned> c(n);
    for (const unsigned q : r) {
        if (!traverse(g, q-1, c, p))
            return no_answer();
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> r(k);
    std::cin >> r;

    std::vector<std::vector<unsigned>> g(n);
    for (size_t i = 0; i < n; ++i) {
        size_t t;
        std::cin >> t;

        g[i].resize(t);
        std::cin >> g[i];
    }

    solve(g, r);

    return 0;
}
