#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<bool>& b, std::vector<bool>& g)
{
    const size_t n = b.size(), m = g.size();

    for (size_t i = 0; i < 2 * n * m; ++i)
        b[i%n] = g[i%m] = (b[i%n] || g[i%m]);

    for (size_t i = 0; i < n; ++i) {
        if (!b[i])
            return answer(false);
    }
    for (size_t i = 0; i < m; ++i) {
        if (!g[i])
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    const auto r = [](std::vector<bool>& p) {
        size_t k;
        std::cin >> k;

        for (size_t i = 0; i < k; ++i) {
            unsigned x;
            std::cin >> x;

            p[x] = true;
        }
    };

    std::vector<bool> b(n);
    r(b);

    std::vector<bool> g(m);
    r(g);

    solve(b, g);

    return 0;
}

