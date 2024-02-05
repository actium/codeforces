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

void solve(const matrix_t& a, const matrix_t& b)
{
    const size_t n = a.size(), m = a[0].size();

    const auto check = [&](size_t r, size_t c) {
        std::vector<unsigned> da, db;
        for (size_t i = r, j = c; ~i != 0 && j < m; --i, ++j) {
            da.push_back(a[i][j]);
            db.push_back(b[i][j]);
        }

        std::sort(da.begin(), da.end());
        std::sort(db.begin(), db.end());
        return da == db;
    };

    for (size_t i = 0; i < n; ++i) {
        if (!check(i, 0))
            return answer(false);
    }
    for (size_t j = 0; j < m; ++j) {
        if (!check(n-1, j))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    matrix_t a(n, std::vector<unsigned>(m));
    std::cin >> a;

    matrix_t b(n, std::vector<unsigned>(m));
    std::cin >> b;

    solve(a, b);

    return 0;
}
