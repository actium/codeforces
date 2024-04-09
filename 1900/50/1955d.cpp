#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size(), m = b.size();

    std::map<unsigned, unsigned> f, g;
    for (const unsigned x : b)
        ++g[x];

    unsigned c = 0;
    for (size_t i = 0; i < m; ++i) {
        const unsigned x = a[i];
        c += (++f[x] <= g[x]);
    }

    unsigned q = (c >= k);
    for (size_t i = m; i < n; ++i) {
        const unsigned x = a[i-m];
        c -= (f[x]-- <= g[x]);

        const unsigned y = a[i];
        c += (++f[y] <= g[y]);

        q += (c >= k);
    }

    answer(q);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, k);
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
