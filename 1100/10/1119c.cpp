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
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const matrix_t& a, const matrix_t& b)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<unsigned> k(m);
    for (size_t i = 0; i < n; ++i) {
        unsigned d = 0;
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                ++k[j];
                ++d;
            }
        }
        if (d % 2 != 0)
            return answer(false);
    }

    for (size_t i = 0; i < m; ++i) {
        if (k[i] % 2 != 0)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    matrix_t a(n, std::vector<unsigned>(m)), b(n, std::vector<unsigned>(m));
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
