#include <iostream>

using point_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned w, unsigned h, const point_t& p1, const point_t& p2, unsigned w2, unsigned h2)
{
    const unsigned w1 = p2.first - p1.first, h1 = p2.second - p1.second;
    if (w1 + w2 > w && h1 + h2 > h)
        return no_answer();

    const unsigned dx = std::min(p1.first < w2 ? w2 - p1.first : 0, w - p2.first < w2 ? w2 - w + p2.first : 0);
    if (h1 + h2 > h)
        return answer(dx);

    const unsigned dy = std::min(p1.second < h2 ? h2 - p1.second : 0, h - p2.second < h2 ? h2 - h + p2.second : 0);
    if (w1 + w2 > w)
        return answer(dy);

    answer(std::min(dx, dy));
}

void test_case()
{
    unsigned w, h;
    std::cin >> w >> h;

    point_t p1, p2;
    std::cin >> p1 >> p2;

    unsigned w2, h2;
    std::cin >> w2 >> h2;

    solve(w, h, p1, p2, w2, h2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
