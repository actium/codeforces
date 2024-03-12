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

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& d, std::vector<unsigned>& f)
{
    const size_t n = a.size(), m = d.size(), k = f.size();

    std::vector<std::pair<unsigned, size_t>> s(n - 1);
    for (size_t i = 1; i < n; ++i)
        s[i-1] = std::make_pair(a[i] - a[i-1], i);

    std::sort(s.begin(), s.end(), std::greater<std::pair<unsigned, size_t>>());

    if (n > 2 && s[0].first == s[1].first)
        return answer(s[0].first);

    const unsigned x = (a[s[0].second-1] + a[s[0].second]) / 2;

    std::sort(d.begin(), d.end());
    std::sort(f.begin(), f.end());

    unsigned b = s[0].first;
    for (size_t i = 0, j = k; i < m && j > 0; ) {
        const unsigned v = d[i] + f[j-1];
        if (v > a[s[0].second-1] && v < a[s[0].second])
            b = std::min(b, std::max(v - a[s[0].second-1], a[s[0].second] - v));

        v < x ? ++i : --j;
    }

    answer(n == 2 ? b : std::max(b, s[1].first));
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), d(m), f(k);
    std::cin >> a >> d >> f;

    solve(a, d, f);
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
