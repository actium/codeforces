#include <iostream>
#include <vector>

#include <climits>

struct Point {
    int x;
    int y;
};

bool operator ==(const Point& lhs, const Point& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

struct Segment {
    Point endpoints[2];
};

std::istream& operator >>(std::istream& input, Segment& s)
{
    return input >> s.endpoints[0].x >> s.endpoints[0].y >> s.endpoints[1].x >> s.endpoints[1].y;
}

bool operator ==(const Segment& lhs, const Segment& rhs)
{
    return lhs.endpoints[0] == rhs.endpoints[0] && lhs.endpoints[1] == rhs.endpoints[1]
        || lhs.endpoints[1] == rhs.endpoints[0] && lhs.endpoints[0] == rhs.endpoints[1];
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<Segment>& s)
{
    Point bl = { INT_MAX, INT_MAX }, tr = { INT_MIN, INT_MIN };
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            bl.x = std::min(bl.x, s[i].endpoints[j].x);
            bl.y = std::min(bl.y, s[i].endpoints[j].y);

            tr.x = std::max(tr.x, s[i].endpoints[j].x);
            tr.y = std::max(tr.y, s[i].endpoints[j].y);
        }
    }

    if (bl.x == tr.x || bl.y == tr.y)
        return answer(false);

    const Point tl = { bl.x, tr.y }, br = { tr.x, bl.y };

    const auto check = [&](const Point& begin, const Point& end) {
        Segment t;
        t.endpoints[0] = begin;
        t.endpoints[1] = end;

        for (Segment& e : s) {
            if (e == t) {
                e = s.back();
                s.pop_back();
                return true;
            }
        }
        return false;
    };

    answer(check(bl, tl) && check(tl, tr) && check(tr, br) && check(br, bl));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<Segment> s(4);
    for (size_t i = 0; i < 4; ++i)
        std::cin >> s[i];

    solve(s);

    return 0;
}
