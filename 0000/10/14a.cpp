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

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    size_t min_i = n, max_i = 0;
    size_t min_j = m, max_j = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] != '*')
                continue;

            min_i = std::min(min_i, i);
            max_i = std::max(max_i, i);
            min_j = std::min(min_j, j);
            max_j = std::max(max_j, j);
        }
    }

    for (size_t i = min_i; i <= max_i; ++i) {
        for (size_t j = min_j; j <= max_j; ++j)
            std::cout << g[i][j];

        std::cout << '\n';
    }

    return 0;
}

