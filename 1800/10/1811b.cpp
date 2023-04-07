#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    const auto r = [n](unsigned x, unsigned y) {
        const unsigned c1 = std::min(x, y), c2 = std::min(n + 1 - x, n + 1 - y);
        return std::min(c1, c2);
    };

    const unsigned r1 = r(x1, y1), r2 = r(x2, y2);
    answer(r1 < r2 ? r2 - r1 : r1 - r2);
}

void test_case()
{
    unsigned n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;

    solve(n, x1, y1, x2, y2);
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
