#include <iostream>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<unsigned> f(n), c(m);
    for (const auto [x, y] : e) {
        --f[x-1];
        ++c[y-1];
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == 1)
                f[i] += c[j];
        }
    }

    answer(f);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(m));
    std::cin >> g;

    std::vector<std::pair<unsigned, unsigned>> e(k);
    std::cin >> e;

    solve(g, e);

    return 0;
}

