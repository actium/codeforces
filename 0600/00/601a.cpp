#include <iostream>
#include <queue>
#include <vector>

constexpr unsigned oo = ~0u;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<bool>>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> t(n, oo);
    std::queue<size_t> q;

    const auto enqueue = [&](size_t x, unsigned d) {
        if (d < t[x]) {
            t[x] = d;
            q.push(x);
        }
    };

    enqueue(0, 0);
    while (!q.empty()) {
        const size_t x = q.front();
        q.pop();

        if (x == n-1)
            return answer(t[x]);

        for (size_t i = 0; i < n; ++i) {
            if (a[x][i] != a[0][n-1])
                enqueue(i, t[x] + 1);
        }
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<bool>> a(n, std::vector<bool>(n));
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        a[u-1][v-1] = true;
        a[v-1][u-1] = true;
    }

    solve(a);

    return 0;
}
