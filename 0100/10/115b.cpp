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

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    g.emplace_back(m, 'G');

    size_t r = 0;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].find('W') != std::string::npos)
            r = i;
    }

    unsigned k = r;
    for (size_t i = 0, x = 0; i <= r; ++i) {
        if (i % 2 == 0) {
            size_t rx = x;
            for (size_t j = x; j < m; ++j) {
                if (g[i][j] == 'W' || g[i+1][j] == 'W')
                    rx = j;
            }

            k += rx - x;
            x = rx;
        } else {
            size_t lx = x;
            for (size_t j = x; ~j != 0; --j) {
                if (g[i][j] == 'W' || g[i+1][j] == 'W')
                    lx = j;
            }

            k += x - lx;
            x = lx;
        }
    }

    answer(k);
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
