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

template <typename F>
bool check(size_t n, size_t m, F&& f)
{
    if ((f(0, 0) ^ f(0, m/3) ^ f(0, 2*m/3)) != ('R' ^ 'G' ^ 'B'))
        return false;

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (f(i, j) != f(i-1, j))
                return false;
        }
    }

    std::vector<size_t> d;
    for (size_t j = 1; j < m; ++j) {
        if (f(0, j) != f(0, j-1))
            d.push_back(j);
    }
    return d.size() == 2 && 3 * d[0] == m && 3 * (d[1] - d[0]) == m;
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    if (check(n, m, [&](size_t i, size_t j) { return g[i][j]; }))
        return answer(true);

    if (check(m, n, [&](size_t j, size_t i) { return g[i][j]; }))
        return answer(true);

    answer(false);
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
