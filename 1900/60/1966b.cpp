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

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    {
        unsigned p = 0, s = 0;
        for (size_t i = 0; i < n; ++i) {
            p += (g[i][0] == 'W');
            s += (g[i][m-1] == 'W');
        }

        if (p == 0 && s == n || p == n && s == 0)
            return answer(false);
    }

    {
        unsigned p = 0, s = 0;
        for (size_t i = 0; i < m; ++i) {
            p += (g[0][i] == 'W');
            s += (g[n-1][i] == 'W');
        }

        if (p == 0 && s == m || p == m && s == 0)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
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
