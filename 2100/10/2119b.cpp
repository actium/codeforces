#include <iostream>
#include <vector>

struct Point {
    unsigned x;
    unsigned y;
};

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

void solve(const std::vector<unsigned>& a, const Point& p, const Point& q)
{
    const auto square = [](int x) {
        return 1LL * x * x;
    };

    const auto d = square(q.x - p.x) + square(q.y - p.y);

    unsigned e = 0, x = 0;
    for (const unsigned v : a) {
        e += v;
        x = std::max(x, v);
    }

    if (d > square(x)) {
        answer(square(e) >= d);
    } else {
        answer(e >= 2 * x || square(2 * x - e) <= d);
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    Point p, q;
    std::cin >> p.x >> p.y >> q.x >> q.y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, p, q);
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
