#include <iostream>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<edge_t>& e)
{
    const size_t n = a.size(), m = e.size();

    if (m % 2 == 0)
        return answer(0);

    std::vector<unsigned> f(1 + n);
    for (const edge_t& x : e) {
        ++f[x.first];
        ++f[x.second];
    }

    unsigned r = ~0u;
    for (size_t i = 1; i <= n; ++i) {
        if (f[i] % 2 == 1)
            r = std::min(r, a[i-1]);
    }
    for (const edge_t& x : e) {
        if (f[x.first] % 2 == 0 && f[x.second] % 2 == 0)
            r = std::min(r, a[x.first-1] + a[x.second-1]);
    }

    answer(r);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<edge_t> e(m);
    std::cin >> e;

    solve(a, e);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
