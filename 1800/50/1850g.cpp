#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Point {
    int x;
    int y;
};

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Point>& p)
{
    integer k = 0;

    std::map<int, unsigned> f[4];
    for (const Point& q : p) {
        k += f[0][q.x]++;
        k += f[1][q.y]++;
        k += f[2][q.x - q.y]++;
        k += f[3][q.x + q.y]++;
    }

    answer(2 * k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<Point> p(n);
    std::cin >> p;

    solve(p);
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
