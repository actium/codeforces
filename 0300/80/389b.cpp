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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(const std::vector<std::string>& g, size_t i, size_t j)
{
    const size_t n = g.size();

    if (j == 0 || j+1 == n || i+1 >= n)
        return false;

    return g[i][j-1] == '#' && g[i][j] == '#' && g[i][j+1] == '#' && g[i+1][j] == '#';
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (g[i][j] == '.')
                continue;

            if (!check(g, i+1, j))
                return answer(false);

            g[i][j] = g[i+1][j-1] = g[i+1][j] = g[i+1][j+1] = g[i+2][j] = '.';
        }
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}

