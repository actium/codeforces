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

    if (n == 1 && m == 1)
        return answer(a[0][0]);

    const auto check = [&](unsigned d) {
        bool t[100][100] = {};
        for (size_t j = 1; j < m && a[0][j] % d == 0; ++j)
            t[0][j] = true;

        for (size_t i = 1; i < n && a[i][0] % d == 0; ++i)
            t[i][0] = true;

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 1; j < m; ++j)
                t[i][j] = (t[i-1][j] || t[i][j-1]) && a[i][j] % d == 0;
        }

        return t[n-1][m-1];
    };

    unsigned x = 1;
    for (unsigned i = 1; i * i <= a[0][0]; ++i) {
        if (a[0][0] % i != 0)
            continue;

        if (check(i))
            x = std::max(x, i);

        if (check(a[0][0] / i))
            x = std::max(x, a[0][0] / i);
    }

    answer(x);
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
