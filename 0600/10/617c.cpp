#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;
using point_t = std::pair<int, int>;

constexpr integer oo = ~integer(0);

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

integer distance(const point_t& s, const point_t& t)
{
    const integer dx = s.first - t.first, dy = s.second - t.second;
    return dx * dx + dy * dy;
}

void solve(const point_t& s1, const point_t& s2, const std::vector<point_t>& t)
{
    const size_t n = t.size();

    std::vector<std::pair<integer, size_t>> d(n);
    for (size_t i = 0; i < n; ++i) {
        d[i].first = distance(s1, t[i]);
        d[i].second = i;
    }

    std::sort(d.begin(), d.end());

    integer r = 0, v = d.back().first;
    while (!d.empty()) {
        r = std::max(r, distance(s2, t[d.back().second]));
        d.pop_back();
        v = std::min(v, r + (d.empty() ? 0 : d.back().first));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    point_t s1, s2;
    std::cin >> s1 >> s2;

    std::vector<point_t> t(n);
    std::cin >> t;

    solve(s1, s2, t);

    return 0;
}
