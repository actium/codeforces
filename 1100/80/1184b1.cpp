#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::vector<size_t> y(m);
    for (size_t i = 0; i < m; ++i)
        y[i] = i;

    std::sort(x.begin(), x.end(), [&a](size_t i, size_t j) { return a[i] < a[j]; });
    std::sort(y.begin(), y.end(), [&b](size_t i, size_t j) { return b[i].first < b[j].first; });

    std::vector<unsigned> g(n);
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (i != 0)
            g[x[i]] = g[x[i-1]];

        while (j < m && a[x[i]] >= b[y[j]].first) {
            g[x[i]] += b[y[j]].second;
            ++j;
        }
    }

    answer(g);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}
