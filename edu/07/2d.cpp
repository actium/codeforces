#include <iostream>
#include <vector>

size_t level(std::vector<size_t>& bosses, std::vector<size_t>& levels, size_t x)
{
    const size_t b = bosses[x];
    if (b != x) {
        levels[x] += level(bosses, levels, b);
        bosses[x] = bosses[b];
    }
    return levels[x];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> bosses(n), levels(n);
    for (size_t i = 0; i < n; ++i)
        bosses[i] = i;

    for (size_t i = 0; i < m; ++i) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned a, b;
            std::cin >> a >> b;
            --a, --b;

            bosses[a] = b;
            ++levels[a];
        } else {
            unsigned c;
            std::cin >> c;
            --c;

            std::cout << level(bosses, levels, c) << '\n';
        }
    }

    return 0;
}
