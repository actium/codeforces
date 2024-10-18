#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& c, integer m)
{
    const size_t n = a.size();

    const auto search = [&](size_t i, size_t j) {
        const integer p = std::min<integer>(m / a[i], c[i]);
        const integer q = std::min<integer>((m - p * a[i]) / a[j], c[j]);
        const integer r = m - p * a[i] - q * a[j];
        const integer x = std::min({ p, c[j] - q, r });

        return (p - x) * a[i] + (q + x) * a[j];
    };

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return a[i] < a[j]; });

    integer k = std::min<integer>(m / a[0], c[0]) * a[0];
    for (size_t i = 1; i < n; ++i) {
        k = std::max(k, std::min<integer>(m / a[i], c[i]) * a[i]);

        if (a[p[i]] - a[p[i-1]] == 1)
            k = std::max(k, search(p[i-1], p[i]));
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer m;
    std::cin >> m;

    std::vector<unsigned> a(n), c(n);
    std::cin >> a >> c;

    solve(a, c, m);
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
