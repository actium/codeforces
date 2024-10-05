#include <iostream>
#include <vector>

std::ostream& operator <<(std::ostream& output, const std::vector<char>& v)
{
    const char* separator = "";
    for (const char x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<char>>& x, const std::vector<std::vector<char>>& y)
{
    std::cout << "YES" << '\n';

    for (const std::vector<char>& v : x)
        std::cout << v << '\n';

    for (const std::vector<char>& v : y)
        std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, size_t m, size_t k)
{
    const size_t d = n + m - 2;

    if (k < d || (k - d) % 2 != 0)
        return no_answer();

    std::vector<std::vector<char>> h(n, std::vector<char>(m-1));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 1; j < m; ++j)
            h[i][j-1] = "RB"[(i+j)%2];
    }
    h[1][0] = 'B';

    std::vector<std::vector<char>> v(n-1, std::vector<char>(m));
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            v[i-1][j] = "RB"[(i+j)%2];
    }
    v[0][0] = 'R';

    answer(h, v);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
