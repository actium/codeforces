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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& g, size_t m)
{
    const size_t n = g.size();

    std::vector<unsigned> rc(n), cc(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '*')
                ++rc[i], ++cc[j];
        }
    }

    unsigned long long k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '*')
                k += (rc[i] - 1) * (cc[j] - 1);
        }
    }
    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g, m);

    return 0;
}

