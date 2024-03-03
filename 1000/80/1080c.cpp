#include <iostream>

using integer = unsigned long long;
using point_t = std::pair<integer, integer>;
using range_t = std::pair<point_t, point_t>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

std::pair<integer, integer> count(const point_t& u, const point_t& v)
{
    const integer q = (v.first - u.first + 1) * (v.second - u.second + 1);

    return (u.first + u.second) % 2 == 0 ? std::make_pair((q + 1) / 2, q / 2) : std::make_pair(q / 2, (q + 1) / 2);
}

range_t intersect(const range_t& u, const range_t& v)
{
    return {
        std::make_pair(std::max(u.first.first, v.first.first), std::max(u.first.second, v.first.second)),
        std::make_pair(std::min(u.second.first, v.second.first), std::min(u.second.second, v.second.second)),
    };
}

void solve(unsigned n, unsigned m, const range_t& u, const range_t& v)
{
    std::pair<integer, integer> a = count(std::make_pair(1, 1), std::make_pair(n, m));

    const std::pair<integer, integer> b = count(u.first, u.second);
    a.first += b.second;
    a.second -= b.second;

    const std::pair<integer, integer> c = count(v.first, v.second);
    a.first -= c.first;
    a.second += c.first;

    const range_t x = intersect(u, v);
    if (x.first.first <= x.second.first && x.first.second <= x.second.second) {
        const std::pair<integer, integer> d = count(x.first, x.second);
        a.first -= d.second;
        a.second += d.second;
    }

    answer(a.first, a.second);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    range_t u, v;
    std::cin >> u >> v;

    solve(n, m, u, v);
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
