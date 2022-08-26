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
    const size_t n = g.size(), m = g[0].length();

    unsigned d = 2;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            const unsigned c = g[i-1][j-1] - '0' + g[i-1][j] - '0' + g[i][j] - '0' + g[i][j-1] - '0';
            d = std::min(d, std::max(2u, c) - 2);
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            k += g[i][j] - '0';
    }

    answer(k - d);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
