#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Robot {
    int x;
    int y;
    unsigned f[4];
};

std::istream& operator >>(std::istream& input, Robot& r)
{
    return input >> r.x >> r.y >> r.f[0] >> r.f[1] >> r.f[2] >> r.f[3];
}

void answer(int x, int y)
{
    std::cout << 1 << ' ' << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << 0 << '\n';
}

void solve(const std::vector<Robot>& r)
{
    std::pair<int, int> rx = { -100000, 100000 }, ry = { -100000, 100000 };
    for (const Robot& q : r) {
        if (q.f[0] == 0)
            rx.first = std::max(rx.first, q.x);
        if (q.f[2] == 0)
            rx.second = std::min(rx.second, q.x);

        if (q.f[1] == 0)
            ry.second = std::min(ry.second, q.y);
        if (q.f[3] == 0)
            ry.first = std::max(ry.first, q.y);
    }

    if (rx.first > rx.second || ry.first > ry.second)
        return no_answer();

    answer(rx.first, ry.first);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<Robot> r(n);
    std::cin >> r;

    solve(r);
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
