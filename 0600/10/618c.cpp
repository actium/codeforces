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

void answer(size_t x, size_t y, size_t z)
{
    std::cout << 1 + x << ' ' << 1 + y << ' ' << 1 + z << '\n';
}

struct Point {
    int x;
    int y;
};

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y;
}

void solve(const std::vector<Point>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&](size_t i, size_t j) {
        return std::make_pair(p[i].x, p[i].y) < std::make_pair(p[j].x, p[j].y);
    });

    const auto check = [&](size_t q) {
        const int dx1 = p[x[q]].x - p[x[1]].x, dy1 = p[x[q]].y - p[x[1]].y;
        const int dx2 = p[x[1]].x - p[x[0]].x, dy2 = p[x[1]].y - p[x[0]].y;
        return 1ll * dx1 * dy2 - 1ll * dy1 * dx2 != 0;
    };

    size_t q = 2;
    while (!check(q))
        ++q;

    answer(x[0], x[1], x[q]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Point> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
