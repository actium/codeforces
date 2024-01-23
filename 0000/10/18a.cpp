#include <iostream>

#include <cmath>

struct Point {
    int x;
    int y;
};

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y;
}

struct Vector {
    int dx;
    int dy;

    Vector(int dx, int dy)
        : dx(dx)
        , dy(dy)
    {}
};

Vector operator -(const Point& lhs, const Point& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

Point operator +(const Point& lhs, const Vector& rhs)
{
    return { lhs.x + rhs.dx, lhs.y + rhs.dy };
}

int dot_product(const Vector& v1, const Vector& v2)
{
    return v1.dx * v2.dx + v1.dy * v2.dy;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

bool check(const Point& p1, const Point& p2, const Point& p3)
{
    const Vector v1 = p1 - p2, v2 = p2 - p3, v3 = p3 - p1;
    if (hypot(v1.dx, v1.dy) + hypot(v2.dx, v2.dy) <= hypot(v3.dx, v3.dy))
        return false;
    if (hypot(v2.dx, v2.dy) + hypot(v3.dx, v3.dy) <= hypot(v1.dx, v1.dy))
        return false;
    if (hypot(v3.dx, v3.dy) + hypot(v1.dx, v1.dy) <= hypot(v2.dx, v2.dy))
        return false;
    return dot_product(v1, v2) == 0 || dot_product(v2, v3) == 0 || dot_product(v3, v1) == 0;

}

void solve(const Point& p1, const Point& p2, const Point& p3)
{
    if (check(p1, p2, p3))
        return answer("RIGHT");

    for (int dx = -1; dx <= 1; ++dx) {
        if (check(p1 + Vector(dx, 0), p2, p3) || check(p1, p2 + Vector(dx, 0), p3) || check(p1, p2, p3 + Vector(dx, 0)))
            return answer("ALMOST");
    }
    for (int dy = -1; dy <= 1; ++dy) {
        if (check(p1 + Vector(0, dy), p2, p3) || check(p1, p2 + Vector(0, dy), p3) || check(p1, p2, p3 + Vector(0, dy)))
            return answer("ALMOST");
    }

    answer("NEITHER");
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    Point p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;

    solve(p1, p2, p3);

    return 0;
}
