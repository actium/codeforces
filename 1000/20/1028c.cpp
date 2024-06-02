#include <iostream>
#include <vector>

constexpr int oo = ~0u >> 1;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

struct Rectangle {
    int x[2] = { -oo, +oo };
    int y[2] = { -oo, +oo };
};

std::istream& operator >>(std::istream& input, Rectangle& r)
{
    return input >> r.x[0] >> r.y[0] >> r.x[1] >> r.y[1];
}

Rectangle intersect(const Rectangle& lhs, const Rectangle& rhs)
{
    return {
        { std::max(lhs.x[0], rhs.x[0]), std::min(lhs.x[1], rhs.x[1]) },
        { std::max(lhs.y[0], rhs.y[0]), std::min(lhs.y[1], rhs.y[1]) },
    };
}

void solve(const std::vector<Rectangle>& r)
{
    const size_t n = r.size();

    std::vector<Rectangle> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = intersect(p[i], r[i]);

    std::vector<Rectangle> s(n + 1);
    for (size_t i = n; i > 0; --i)
        s[i-1] = intersect(s[i], r[i-1]);

    Rectangle x = intersect(p[0], s[1]);
    for (size_t i = 0; x.x[0] > x.x[1] || x.y[0] > x.y[1]; x = intersect(p[i], s[i+1]))
        ++i;

    answer(x.x[0], x.y[0]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Rectangle> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
