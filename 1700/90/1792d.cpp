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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<std::vector<unsigned>> p(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            p[i][a[i][j]-1] = j + 1;
    }

    std::sort(p.begin(), p.end());

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        const size_t j = std::lower_bound(p.begin(), p.end(), a[i]) - p.begin();
        if (j > 0)
            c[i] = std::max<unsigned>(c[i], std::mismatch(a[i].begin(), a[i].end(), p[j-1].begin()).first - a[i].begin());
        if (j < n)
            c[i] = std::max<unsigned>(c[i], std::mismatch(a[i].begin(), a[i].end(), p[j-0].begin()).first - a[i].begin());
    }

    answer(c);
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
