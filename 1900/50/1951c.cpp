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

void solve(const std::vector<unsigned>& a, unsigned m, unsigned k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return a[i] < a[j];
    });

    std::vector<unsigned> c(n);
    for (size_t i = 0; k != 0; k -= c[p[i++]])
        c[p[i]] = std::min(m, k);

    integer d = 0, v = 0;
    for (size_t i = 0; i < n; ++i) {
        v += c[i] * (a[i] + d);
        d += c[i];
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);
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
