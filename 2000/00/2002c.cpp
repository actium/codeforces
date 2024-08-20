#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

long long distance(const point_t& s, const point_t& t)
{
    const int dx = t.first - s.first, dy = t.second - s.second;
    return 1ll * dx * dx + 1ll * dy * dy;
}

void solve(const std::vector<point_t>& p, const point_t& s, const point_t& t)
{
    const auto d = distance(s, t);

    for (const point_t& q : p) {
        if (distance(q, t) <= d)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(n);
    std::cin >> p;

    point_t s, t;
    std::cin >> s >> t;

    solve(p, s, t);
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
