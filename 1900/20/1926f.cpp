#include <array>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

bool check(const std::array<std::string, 7>& g, unsigned d)
{
    for (size_t i = 1; i < 6; ++i) {
        for (size_t j = 1; j < 6; ++j) {
            if ((i + j) % 2 != d)
                continue;

            if (g[i-1][j-1] == 'B' && g[i-1][j+1] == 'B' && g[i][j] == 'B' && g[i+1][j-1] == 'B' && g[i+1][j+1] == 'B')
                return false;
        }
    }
    return true;
}

unsigned search(std::array<std::string, 7>& g, const std::vector<std::pair<size_t, size_t>>& p, unsigned d)
{
    const unsigned m = 1 << p.size();

    const auto flip = [&](unsigned x) {
        while (x != 0) {
            const size_t i = __builtin_ctz(x);
            g[p[i].first][p[i].second] ^= 'B' ^ 'W';
            x &= x - 1;
        }
    };

    unsigned k = oo;
    for (unsigned i = 0; i < m; ++i) {
        flip(i);

        if (check(g, d))
            k = std::min<unsigned>(k, __builtin_popcount(i));

        flip(i);
    }

    return k;
}

void solve(std::array<std::string, 7>& g)
{
    std::vector<std::pair<size_t, size_t>> p[2];
    for (size_t i = 1; i < 6; ++i) {
        for (size_t j = 1; j < 6; ++j) {
            if (g[i][j] == 'B')
                p[(i + j) % 2].emplace_back(i, j);
        }
    }

    answer(search(g, p[0], 0) + search(g, p[1], 1));
}

void test_case()
{
    std::array<std::string, 7> g;
    std::cin >> g;

    solve(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
