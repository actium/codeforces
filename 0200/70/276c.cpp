#include <algorithm>
#include <iostream>
#include <vector>

using range_t = std::pair<unsigned, unsigned>;
using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<range_t>& r)
{
    const size_t n = a.size();

    std::vector<int> d(n+1);
    for (const range_t& q : r) {
        ++d[q.first-1];
        --d[q.second];
    }

    for (size_t i = 1; i < n; ++i)
        d[i] += d[i-1];

    std::sort(a.begin(), a.end(), std::greater<unsigned>());
    std::sort(d.begin(), d.end(), std::greater<int>());

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += 1ull * d[i] * a[i];

    answer(s);
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<range_t> r(q);
    std::cin >> r;

    solve(a, r);

    return 0;
}
