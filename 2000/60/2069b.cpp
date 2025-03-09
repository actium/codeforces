#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    const auto check = [&](size_t i, size_t j, unsigned x) {
        return i < n && j < m && a[i][j] == x;
    };

    std::vector<unsigned> f(1 + n * m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const unsigned x = a[i][j];

            if (f[x] == 0)
                f[x] = 1;

            if (check(i-1, j, x) || check(i+1, j, x) || check(i, j-1, x) || check(i, j+1, x))
                f[x] = 2;
        }
    }

    unsigned s = 0, b = 0;
    for (size_t i = 1; i <= n * m; ++i) {
        s += f[i];
        b = std::max(b, f[i]);
    }

    answer(s - b);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
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
