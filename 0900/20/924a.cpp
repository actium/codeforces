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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].length();

    const auto check = [&](size_t i, size_t j) {
        for (size_t k = 0; k < n; ++k) {
            if (g[k][j] == '#' && g[k] != g[i])
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '#' && !check(i, j))
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}

