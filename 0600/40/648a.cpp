#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].length();

    std::vector<unsigned> h(m);
    for (size_t j = 0; j < m; ++j)
        for (size_t i = n; i-- > 0 && g[i][j] == '*'; ++h[j]);

    unsigned u = 0, d = 0;
    for (size_t j = 1; j < m; ++j) {
        if (h[j] > h[j-1])
            u = std::max(u, h[j] - h[j-1]);
        else
            d = std::max(d, h[j-1] - h[j]);
    }

    answer(u, d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}
