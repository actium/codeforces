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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].length();

    std::vector<unsigned> r(n), c(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '.')
                ++r[i], ++c[j];
        }
    }

    unsigned k = ~0u;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            k = std::min(k, r[i] + c[j] - (g[i][j] == '.'));
    }

    answer(k);
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

