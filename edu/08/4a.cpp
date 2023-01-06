#include <iostream>
#include <vector>

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> x(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        x[u-1][v-1] = 1;
        x[v-1][u-1] = 1;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            std::cout << x[i][j] << ' ';

        std::cout << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
