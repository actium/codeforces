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

void solve(const std::vector<std::string>& x, size_t m)
{
    const size_t n = x.size();

    size_t min_i = n, max_i = 0, min_j = m, max_j = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (x[i][j] != '*')
                continue;

            min_i = std::min(min_i, i);
            max_i = std::max(max_i, i);
            min_j = std::min(min_j, j);
            max_j = std::max(max_j, j);
        }
    }

    for (const size_t i : { min_i, max_i }) {
        for (const size_t j : { min_j, max_j }) {
            if (x[i][j] != '*')
                std::cout << 1+i << ' ' << 1+j;
        }
    }
    std::cout << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> x(n);
    std::cin >> x;

    solve(x, m);

    return 0;
}

