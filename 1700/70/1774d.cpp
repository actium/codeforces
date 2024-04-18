#include <array>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::array<size_t, 3>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::array<size_t, 3>& x : v)
        std::cout << 1 + x[0] << ' ' << 1 + x[1] << ' ' << 1 + x[2] << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<unsigned> f(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            f[i] += a[i][j];
    }

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i)
        s += f[i];

    if (s % n != 0)
        return no_answer();

    s /= n;

    std::vector<std::array<size_t, 3>> ops;
    for (size_t j = 0; j < m; ++j) {
        std::vector<size_t> p[2];
        for (size_t i = 0; i < n; ++i) {
            if (f[i] < s && a[i][j] == 0)
                p[0].push_back(i);

            if (f[i] > s && a[i][j] == 1)
                p[1].push_back(i);
        }

        while (!p[0].empty() && !p[1].empty()) {
            ops.push_back({ p[0].back(), p[1].back(), j });

            ++f[p[0].back()];
            --f[p[1].back()];

            p[0].pop_back();
            p[1].pop_back();
        }
    }

    answer(ops);
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
