#include <iostream>
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

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<std::pair<int, int>>> b(n, std::vector<std::pair<int, int>>(m));
    b[0][0] = std::make_pair(a[0][0], a[0][0]);
    for (size_t i = 1; i < n; ++i) {
        b[i][0].first = b[i-1][0].first + a[i][0];
        b[i][0].second = b[i-1][0].second + a[i][0];
    }
    for (size_t j = 1; j < m; ++j) {
        b[0][j].first = b[0][j-1].first + a[0][j];
        b[0][j].second = b[0][j-1].second + a[0][j];
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            b[i][j].first = std::min(b[i-1][j].first, b[i][j-1].first) + a[i][j];
            b[i][j].second = std::max(b[i-1][j].second, b[i][j-1].second) + a[i][j];
        }
    }

    answer(b[n-1][m-1].first <= 0 && b[n-1][m-1].second >= 0 && b[n-1][m-1].second % 2 == 0);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::cin >> a;

    solve(a);
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
