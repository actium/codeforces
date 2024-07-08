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

void solve(std::vector<std::string>& a, const std::vector<std::string>& b)
{
    const size_t n = a.size(), m = a[0].size();

    const auto add = [&](size_t r, size_t c, int d) {
        a[r][c] += (a[r][c] + d > '2' ? d - 3 : d);
    };

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < m; ++j) {
            while (a[i-1][j-1] != b[i-1][j-1]) {
                add(i-1, j-1, 1);
                add(i-1, j, 2);
                add(i, j-1, 2);
                add(i, j, 1);
            }
        }
    }

    answer(a == b);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
