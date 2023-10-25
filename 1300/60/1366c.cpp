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
    const size_t n = a.size(), m = a[0].size(), k = n + m - 1;

    unsigned f[60][2] = {};
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            ++f[i+j][a[i][j]];
    }

    unsigned q = 0;
    for (size_t i = 0; i < k / 2; ++i)
        q += std::min(f[i][0] + f[k-1-i][0], f[i][1] + f[k-1-i][1]);

    answer(q);
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
