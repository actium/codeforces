#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(1+n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        c[u] += (v > u);
        c[v] += (u > v);
    }

    unsigned k = 0;
    for (size_t i = 1; i <= n; ++i)
        k += (c[i] == 0);

    size_t q;
    std::cin >> q;

    while (q--) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned u, v;
            std::cin >> u >> v;

            k -= (c[u] == 0 && v > u);
            k -= (c[v] == 0 && u > v);

            c[u] += (v > u);
            c[v] += (u > v);
        }
        if (t == 2) {
            unsigned u, v;
            std::cin >> u >> v;

            k += (c[u] == 1 && v > u);
            k += (c[v] == 1 && u > v);

            c[u] -= (v > u);
            c[v] -= (u > v);
        }
        if (t == 3) {
            answer(k);
        }
    }

    return 0;
}
