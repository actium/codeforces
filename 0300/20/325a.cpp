#include <iostream>
#include <vector>

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

struct Rectangle {
    unsigned x[2];
    unsigned y[2];

    unsigned dx() const
    {
        return x[1] - x[0];
    }

    unsigned dy() const
    {
        return y[1] - y[0];
    }
};

std::istream& operator >>(std::istream& input, Rectangle& r)
{
    return input >> r.x[0] >> r.y[0] >> r.x[1] >> r.y[1];
}

void solve(const std::vector<Rectangle>& r)
{
    Rectangle b = { { ~0u, 0 }, { ~0u, 0 } };

    unsigned s = 0;
    for (const Rectangle& q : r) {
        b.x[0] = std::min(b.x[0], q.x[0]);
        b.x[1] = std::max(b.x[1], q.x[1]);
        b.y[0] = std::min(b.y[0], q.y[0]);
        b.y[1] = std::max(b.y[1], q.y[1]);

        s += q.dx() * q.dy();
    }

    answer(b.dx() == b.dy() && b.dx() * b.dy() == s);
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
