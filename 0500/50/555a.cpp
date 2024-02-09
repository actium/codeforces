#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& c)
{
    unsigned k = 0;
    for (const std::vector<unsigned>& v : c) {
        if (v[0] != 1) {
            k += v.size() * 2 - 1;
        } else {
            size_t i = 0;
            while (i < v.size() && v[i] == 1 + i)
                ++i;

            k += (v.size() - i) * 2;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::vector<unsigned>> c(k);
    for (size_t i = 0; i < k; ++i) {
        size_t m;
        std::cin >> m;

        c[i].resize(m);
        for (size_t j = 0; j < m; ++j)
            std::cin >> c[i][j];
    }

    solve(c);

    return 0;
}
