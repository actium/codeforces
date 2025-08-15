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

unsigned maximize(const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b)
{
    unsigned v[4] = { a.first, a.second, b.first, b.second };
    std::sort(std::begin(v), std::end(v));
    return v[2] - v[0] + v[3] - v[1];
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = std::minmax(a[i], b[i]);

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += p[i].second - p[i].first;

    std::sort(p.begin(), p.end());

    unsigned d = ~0u;
    for (size_t i = 1; i < n; ++i)
        d = std::min(d, maximize(p[i-1], p[i]) - (p[i-1].second - p[i-1].first + p[i].second - p[i].first));

    answer(s + d);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
