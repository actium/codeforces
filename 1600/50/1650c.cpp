#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void answer(integer u, const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << u << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(const std::vector<std::pair<int, int>>& p, size_t n)
{
    const size_t m = p.size();

    std::vector<size_t> o(m);
    for (size_t i = 0; i < m; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&p](size_t x, size_t y) { return p[x].second < p[y].second; });

    o.resize(2 * n);

    std::sort(o.begin(), o.end(), [&p](size_t x, size_t y) { return p[x].first < p[y].first; });

    integer w = 0;
    for (const size_t i : o)
        w += p[i].second;

    std::vector<std::pair<size_t, size_t>> r(n);
    for (size_t i = 0; i < n; ++i) {
        r[i].first = o[i];
        r[i].second = o[2*n-1-i];
    }

    answer(w, r);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> p(m);
    std::cin >> p;

    solve(p, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
