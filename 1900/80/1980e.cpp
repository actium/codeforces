#include <algorithm>
#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<unsigned>>;

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

bool check(std::vector<size_t>& s)
{
    std::sort(s.begin(), s.end());

    return std::unique(s.begin(), s.end()) == std::next(s.begin());
}

void solve(const matrix_t& a, const matrix_t& b)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<size_t> rx(n * m), cx(n * m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            rx[a[i][j]-1] = i;
            cx[a[i][j]-1] = j;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        std::vector<size_t> s;
        for (size_t j = 0; j < m; ++j)
            s.push_back(rx[b[i][j]-1]);

        if (!check(s))
            return answer(false);
    }

    for (size_t j = 0; j < m; ++j) {
        std::vector<size_t> s;
        for (size_t i = 0; i < n; ++i)
            s.push_back(cx[b[i][j]-1]);

        if (!check(s))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    matrix_t a(n, std::vector<unsigned>(m)), b(n, std::vector<unsigned>(m));
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
