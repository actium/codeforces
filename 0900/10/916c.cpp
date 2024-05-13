#include <iostream>
#include <vector>

struct Edge {
    unsigned u;
    unsigned v;
    unsigned w;
};

void answer(unsigned u, const std::vector<Edge>& v)
{
    std::cout << u << ' ' << u << '\n';

    for (const Edge& x : v)
        std::cout << x.u << ' ' << x.v << ' ' << x.w << '\n';
}

void solve(unsigned n, unsigned m)
{
    std::vector<Edge> e;
    e.push_back({ 1, 2, 100005 - n });
    for (unsigned i = 2; i < n; ++i)
        e.push_back({ i, i + 1, 1 });

    for (unsigned i = 1, j = 3; e.size() < m; ++j) {
        if (j == n + 1) {
            ++i;
            j = i + 2;
        }
        e.push_back({ i, j, 100000 + 2 * n });
    }

    answer(100003, e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
