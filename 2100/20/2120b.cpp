#include <iostream>
#include <vector>

struct Ball {
    unsigned x;
    unsigned y;

    int dx;
    int dy;
};

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Ball>& b, unsigned s)
{
    unsigned k = 0;
    for (const Ball& q : b) {
        const unsigned dx = (q.dx == -1 ? q.x : s - q.x), dy = (q.dy == -1 ? q.y : s - q.y);
        k += (dx == dy);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<Ball> b(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> b[i].dx >> b[i].dy >> b[i].x >> b[i].y;

    solve(b, s);
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
