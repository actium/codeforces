#include <iostream>

using integer = unsigned long long;

struct Rectangle {
    unsigned x[2];
    unsigned y[2];

    Rectangle intersect(const Rectangle& other) const
    {
        const unsigned lx = std::max(x[0], other.x[0]);
        const unsigned rx = std::min(x[1], other.x[1]);
        const unsigned by = std::max(y[0], other.y[0]);
        const unsigned ty = std::min(y[1], other.y[1]);

        if (lx < rx && ty > by)
            return { { lx, rx }, { by, ty } };

        return { { 0, 0 }, { 0, 0 } };
    }

    integer compute_area() const
    {
        return integer(x[1] - x[0]) * (y[1] - y[0]);
    }
};

std::istream& operator >>(std::istream& input, Rectangle& r)
{
    return input >> r.x[0] >> r.y[0] >> r.x[1] >> r.y[1];
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const Rectangle& w, const Rectangle& b1, const Rectangle& b2)
{
    const Rectangle x1 = w.intersect(b1);
    const Rectangle x2 = w.intersect(b2);
    const Rectangle x3 = x1.intersect(x2);

    answer(x1.compute_area() + x2.compute_area() - x3.compute_area() < w.compute_area());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    Rectangle w, b1, b2;
    std::cin >> w >> b1 >> b2;

    solve(w, b1, b2);

    return 0;
}
