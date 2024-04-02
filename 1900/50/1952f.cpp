#include <array>
#include <iostream>
#include <string>

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

void solve(const std::array<std::string, 21>& g)
{
    unsigned ps[22][22] = {};
    for (size_t i = 0; i < 21; ++i) {
        for (size_t j = 0; j < 21; ++j)
            ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j] + (g[i][j] - '0');
    }

    unsigned x = 0;
    for (size_t i = 4; i <= 21; ++i) {
        for (size_t j = 4; j <= 21; ++j)
            x = std::max(x, ps[i][j] - ps[i-4][j] - ps[i][j-4] + ps[i-4][j-4]);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<std::string, 21> g;
    std::cin >> g;

    solve(g);

    return 0;
}
