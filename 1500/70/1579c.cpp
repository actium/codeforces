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

void solve(std::vector<std::string>& g, size_t k)
{
    using count_t = std::pair<unsigned, unsigned>;

    const size_t n = g.size(), m = g[0].length();

    std::vector<std::vector<count_t>> q(n, std::vector<count_t>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '*') {
                q[i][j].first = (i > 0 && j > 0 ? q[i-1][j-1].first : 0) + 1;
                q[i][j].second = (i > 0 && j + 1 < m ? q[i-1][j+1].second : 0) + 1;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const unsigned d = std::min(q[i][j].first, q[i][j].second);
            if (d <= k)
                continue;

            for (size_t c = 0; c < d; ++c) {
                g[i-c][j-c] = '.';
                g[i-c][j+c] = '.';
            }
        }
    }

    for (const std::string& r : g) {
        if (r.find('*') != std::string::npos)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
