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

    std::vector<bool> z(m);
    for (size_t i = 0; i < n; ++i) {
        bool x = false;
        for (size_t j = 0; j < m; ++j) {
            if (g[i][j] == '0') {
                z[j] = true;
                x = true;
            }

            if (g[i][j] == '1' && z[j] && x)
                return answer(false);
        }
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
