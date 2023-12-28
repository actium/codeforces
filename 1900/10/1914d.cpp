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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return a[i] > a[j]; });
    const size_t pa[3] = { p[0], p[1], p[2] };

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return b[i] > b[j]; });
    const size_t pb[3] = { p[0], p[1], p[2] };

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return c[i] > c[j]; });
    const size_t pc[3] = { p[0], p[1], p[2] };

    unsigned v = 0;

    const auto check = [&](size_t x, size_t y, size_t z) {
        if (pa[x] != pb[y] && pa[x] != pc[z] && pb[y] != pc[z])
            v = std::max(v, a[pa[x]] + b[pb[y]] + c[pc[z]]);
    };

    for (size_t x = 0; x < 3; ++x) {
        for (size_t y = 0; y < 3; ++y) {
            for (size_t z = 0; z < 3; ++z)
                check(x, y, z);
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n), c(n);
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
