#include <iostream>
#include <vector>

struct Rectangle {
    unsigned x1, y1;
    unsigned x2, y2;
};

std::istream& operator >>(std::istream& input, Rectangle& v)
{
    return input >> v.x1 >> v.y1 >> v.x2 >> v.y2;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<Rectangle>& r)
{
    unsigned k = 0;
    for (const Rectangle& a : r) {
        const unsigned s = (a.x2 - a.x1 + 1) * (a.y2 - a.y1 + 1);
        k += s;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Rectangle> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}

