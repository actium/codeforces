#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    if (f(lb))
        return lb;

    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb + 1;
}

struct Road {
    size_t b;
    unsigned c;
};

std::vector<unsigned> route(const std::vector<std::vector<Road>>& g, unsigned ub)
{
    const size_t n = g.size();

    std::vector<unsigned> p(n);
    const auto restore_path = [&p](unsigned v) {
        std::vector<unsigned> path;
        while (v != 0) {
            path.push_back(v);
            v = p[v-1];
        }
        return path;
    };

    std::queue<size_t> q;
    for (q.emplace(0); !q.empty(); q.pop()) {
        const size_t v = q.front();
        if (v == n-1)
            return restore_path(n);

        for (const Road& u : g[v]) {
            if (u.c <= ub && p[u.b] == 0) {
                p[u.b] = 1+v;
                q.emplace(u.b);
            }
        }
    }

    return {};
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() - 1 << '\n';

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << '\n';
}

void solve(const std::vector<std::vector<Road>>& g, size_t d)
{
    const auto f = [&](unsigned ub) {
        const auto path = route(g, ub);
        return !path.empty() && path.size() <= d;
    };

    const auto path = route(g, search(0, 1000000000, f));
    if (path.empty() || path.size() > d+1)
        return no_answer();

    answer(path);
}

int main()
{
    size_t n, m, d;
    std::cin >> n >> m >> d;

    std::vector<std::vector<Road>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b, c;
        std::cin >> a >> b >> c;

        g[a-1].push_back({ b-1, c });
    }

    solve(g, d);

    return 0;
}

