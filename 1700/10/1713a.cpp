#include <iostream>
#include <vector>

using point_t = std::pair<int, int>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<point_t>& p)
{
    int lx = 0, ux = 0, ly = 0, uy = 0;
    for (const point_t& q : p) {
        lx = std::min(lx, q.first);
        ux = std::max(ux, q.first);
        ly = std::min(ly, q.second);
        uy = std::max(uy, q.second);
    }

    answer(2 * (uy - ly) + 2 * (ux - lx));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(n);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
