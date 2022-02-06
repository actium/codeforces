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
    constexpr const char* s[2] = { "Impossible", "Possible" };
    std::cout << s[v] << '\n';
}

void solve(matrix_t& a, matrix_t& b)
{
    const size_t n = a.size(), m = a[0].size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] > b[i][j])
                std::swap(a[i][j], b[i][j]);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i != 0 && (a[i][j] <= a[i-1][j] || b[i][j] <= b[i-1][j]))
                return answer(false);

            if (j != 0 && (a[i][j] <= a[i][j-1] || b[i][j] <= b[i][j-1]))
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    matrix_t a(n, std::vector<unsigned>(m)), b(n, std::vector<unsigned>(m));
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
