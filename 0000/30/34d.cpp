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
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void traverse(const std::vector<std::vector<size_t>>& g, size_t u, size_t p, std::vector<size_t>& q)
{
    q[u] = p;

    for (const size_t v : g[u]) {
        if (v != p)
            traverse(g, v, u, q);
    }
}

void solve(const std::vector<unsigned>& p, unsigned s, unsigned t)
{
    const size_t n = p.size() + 1;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < s - 1; ++i) {
        const size_t x = p[i] - 1;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    for (size_t i = s; i < n; ++i) {
        const size_t x = p[i-1] - 1;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    std::vector<size_t> q(n);
    traverse(g, t-1, t-1, q);

    q.erase(q.begin() + t - 1);
    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned s, t;
    std::cin >> s >> t;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    solve(p, s, t);

    return 0;
}
