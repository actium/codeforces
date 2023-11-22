#include <algorithm>
#include <iostream>

#include <cmath>

struct Point {
    int x;
    int y;
};

const Point o = { 0, 0 };

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y;
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

unsigned d(const Point& s, const Point& t)
{
    const int dx = t.x - s.x, dy = t.y - s.y;

    return dx * dx + dy * dy;
}

void solve(const Point& p, const Point& a, const Point& b)
{
    const unsigned oa = d(o, a), ob = d(o, b), ab = d(a, b), ap = d(a, p), bp = d(b, p);

    const unsigned w = std::min({
        4 * std::max(oa, ap),
        4 * std::max(ob, bp),
        std::max({ ab, 4 * oa, 4 * bp }),
        std::max({ ab, 4 * ob, 4 * ap }),
    });

    answer(sqrt(w) / 2);
}

void test_case()
{
    Point p, a, b;
    std::cin >> p >> a >> b;

    solve(p, a, b);
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
