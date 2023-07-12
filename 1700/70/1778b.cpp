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

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& a, unsigned d)
{
    const size_t n = p.size(), m = a.size();

    std::vector<size_t> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    unsigned k = ~0u;
    for (size_t i = 1; i < m; ++i) {
        const size_t u = x[a[i-1]], v = x[a[i]];
        if (u < v && v <= u + d) {
            k = std::min<unsigned>(k, v - u);
            if (n - 1 > d)
                k = std::min<unsigned>(k, d - (v - u) + 1);
        } else {
            k = 0;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> p(n), a(m);
    std::cin >> p >> a;

    solve(p, a, d);
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
