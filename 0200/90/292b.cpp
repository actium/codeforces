#include <iostream>
#include <vector>

void answer(const char* v)
{
    std::cout << v << ' ' << "topology" << '\n';
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    unsigned f[3] = {};
    for (const auto& r : g)
        ++f[(r.size() > 1) + (r.size() > 2)];

    if (f[0] == 2 && f[1] != 0 && f[2] == 0)
        return answer("bus");

    if (f[0] == 0 && f[1] != 0 && f[2] == 0)
        return answer("ring");

    if (f[0] != 0 && f[1] == 0 && f[2] == 1)
        return answer("star");

    answer("unknown");
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g);

    return 0;
}

