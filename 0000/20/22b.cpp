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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    const auto check = [&](size_t r, size_t c, size_t h, size_t w) {
        for (size_t i = 0; i < h; ++i) {
            for (size_t j = 0; j < w; ++j) {
                if (g[r+i][c+j] == '1')
                    return false;
            }
        }
        return true;
    };

    unsigned p = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t h = n - i; h > 0; --h) {
                for (size_t w = m - j; w > 0; --w) {
                    if (2 * (h + w) > p && check(i, j, h, w))
                        p = 2 * (h + w);
                }
            }
        }
    }

    answer(p);
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
