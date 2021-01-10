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

void solve(const std::vector<std::string>& g, size_t k)
{
    const size_t n = g.size(), m = g[0].length();

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned f = 0;
        for (size_t j = 0; j < m; ++j) {
            f = (g[i][j] == '.' ? f+1 : 0);
            if (f >= k)
                ++c;
        }
    }
    for (size_t j = 0; j < m; ++j) {
        unsigned f = 0;
        for (size_t i = 0; i < n; ++i) {
            f = (g[i][j] == '.' ? f+1 : 0);
            if (f >= k)
                ++c;
        }
    }

    answer(k > 1 ? c : c / 2);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g, k);

    return 0;
}

