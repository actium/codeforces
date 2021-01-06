#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& g)
{
    constexpr const char* p[6] = { "RGB", "RBG", "GRB", "GBR", "BRG", "BGR" };

    const size_t n = g.length();

    unsigned k[6] = {};
    for (size_t i = 0; i < 6; ++i) {
        for (size_t j = 0; j < n; ++j)
            k[i] += (g[j] != p[i][j % 3]);
    }

    size_t x = 0;
    for (size_t i = 1; i < 6; ++i) {
        if (k[i] < k[x])
            x = i;
    }

    for (size_t i = 0; i < n; ++i)
        g[i] = p[x][i % 3];

    answer(k[x], g);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string g;
    std::cin >> g;

    solve(g);

    return 0;
}

