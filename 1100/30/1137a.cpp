#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

template <typename F>
void compress(std::vector<unsigned>& v, F&& f)
{
    const size_t n = v.size();

    for (size_t i = 0; i < n; ++i)
        v[i] = f(i);

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> r(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i)
        compress(r[i], [&](size_t j) { return a[i][j]; });

    std::vector<std::vector<unsigned>> c(m, std::vector<unsigned>(n));
    for (size_t j = 0; j < m; ++j)
        compress(c[j], [&](size_t i) { return a[i][j]; });

    std::vector<std::vector<unsigned>> v(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const auto it = std::lower_bound(r[i].begin(), r[i].end(), a[i][j]);
            const auto jt = std::lower_bound(c[j].begin(), c[j].end(), a[i][j]);

            v[i][j] += std::max(it - r[i].begin(), jt - c[j].begin());
            v[i][j] += std::max(r[i].end() - it, c[j].end() - jt);
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}
