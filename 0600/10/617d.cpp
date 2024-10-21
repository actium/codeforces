#include <array>
#include <iostream>

struct Point {
    int x;
    int y;
};

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::array<Point, 3>& p)
{
    if (p[0].x == p[1].x && p[1].x == p[2].x || p[0].y == p[1].y && p[1].y == p[2].y)
        return answer(1);

    for (size_t i = 1; i < 3; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const size_t k = 3 ^ i ^ j;

            if (p[i].x == p[j].x && (p[k].y <= std::min(p[i].y, p[j].y) || p[k].y >= std::max(p[i].y, p[j].y)))
                return answer(2);

            if (p[i].y == p[j].y && (p[k].x <= std::min(p[i].x, p[j].x) || p[k].x >= std::max(p[i].x, p[j].x)))
                return answer(2);
        }
    }

    answer(3);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<Point, 3> p;
    std::cin >> p[0] >> p[1] >> p[2];

    solve(p);

    return 0;
}
