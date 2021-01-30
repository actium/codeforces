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

template <typename F>
double search(double lb, double ub, F&& f)
{
    for (unsigned k = 0; k < 100; ++k) {
        const double mid = (lb + ub) / 2;
        if (f(mid))
            ub = mid;
        else
            lb = mid;
    }
    return ub;
}

struct Road {
    size_t b;
    unsigned c;
};

struct Waypoint {
    size_t b;
    double c;

    bool operator <(const Waypoint& w) const
    {
        return c > w.c;
    }
};

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() - 1 << '\n';

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << '\n';
}

bool route(const std::vector<std::vector<Road>>& g, std::vector<std::pair<unsigned, double>>& p, double x)
{
    const size_t n = g.size();

    for (size_t i = 0; i < n; ++i)
        p[i].first = 0;

    std::priority_queue<Waypoint> q;
    q.push({ 0, 0 });
    while (!q.empty()) {
        const Waypoint w = q.top();
        if (w.b == n-1 && w.c <= 0)
            return true;

        q.pop();
        for (const Road& u : g[w.b]) {
            if (p[u.b].first == 0 || w.c + u.c - x < p[u.b].second) {
                p[u.b].first = 1+w.b;
                p[u.b].second = w.c + u.c - x;
                q.push({ u.b, p[u.b].second });
            }
        }
    }
    return false;
}

void solve(const std::vector<std::vector<Road>>& g)
{
    const size_t n = g.size();

    std::vector<std::pair<unsigned, double>> p(n);
    const auto restore_path = [&] {
        std::vector<unsigned> path;
        for (unsigned v = n; v != 0; v = p[v-1].first)
            path.push_back(v);

        return path;
    };

    const double x = search(0, 100, [&](double x) { return route(g, p, x); });
    route(g, p, x);
    answer(restore_path());
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<Road>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b, c;
        std::cin >> a >> b >> c;

        g[a-1].push_back({ b-1, c });
    }

    solve(g);

    return 0;
}

