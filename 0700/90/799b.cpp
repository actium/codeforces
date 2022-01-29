#include <algorithm>
#include <iostream>
#include <vector>

using colors_t = std::vector<unsigned>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& p, const colors_t& a, const colors_t& b, const colors_t& c)
{
    const size_t n = p.size(), m = c.size();

    std::vector<size_t> x[3];
    for (size_t i = 0; i < n; ++i) {
        x[a[i]-1].push_back(i);
        x[b[i]-1].push_back(i);
    }

    std::sort(x[0].begin(), x[0].end(), [&p](size_t a, size_t b) { return p[a] < p[b]; });
    std::sort(x[1].begin(), x[1].end(), [&p](size_t a, size_t b) { return p[a] < p[b]; });
    std::sort(x[2].begin(), x[2].end(), [&p](size_t a, size_t b) { return p[a] < p[b]; });

    std::vector<size_t>::const_iterator it[3] = { x[0].cbegin(), x[1].cbegin(), x[2].cbegin() };

    std::vector<int> r(m, -1);
    for (size_t i = 0; i < m; ++i) {
        const size_t q = c[i] - 1;

        while (it[q] != x[q].cend() && p[*it[q]] == ~0u)
            ++it[q];

        if (it[q] != x[q].cend())
            r[i] = std::exchange(p[*it[q]++], ~0u);
    }

    answer(r);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), a(n), b(n);
    std::cin >> p >> a >> b;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> c(m);
    std::cin >> c;

    solve(p, a, b, c);

    return 0;
}
