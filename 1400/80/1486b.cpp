#include <algorithm>
#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;
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

void solve(std::vector<point_t>& p)
{
    const size_t n = p.size();

    std::sort(p.begin(), p.end(), [](const point_t& a, const point_t& b) { return a.first < b.first; });
    const unsigned dx = p[n/2].first - p[(n-1)/2].first;

    std::sort(p.begin(), p.end(), [](const point_t& a, const point_t& b) { return a.second < b.second; });
    const unsigned dy = p[n/2].second - p[(n-1)/2].second;

    answer((dx + 1ull) * (dy + 1ull));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
