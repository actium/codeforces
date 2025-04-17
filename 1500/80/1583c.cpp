#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<std::string>& g, const std::vector<std::pair<unsigned, unsigned>>& x)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<unsigned> p(1+m);
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            if (g[i-1][j] == 'X' && g[i][j-1] == 'X')
                p[j+1] = 1;
        }
    }

    for (size_t j = 1; j <= m; ++j)
        p[j] += p[j-1];

    for (const std::pair<unsigned, unsigned>& r : x)
        answer(p[r.second] == p[r.first]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> x(q);
    std::cin >> x;

    solve(g, x);

    return 0;
}
