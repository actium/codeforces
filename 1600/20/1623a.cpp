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

void solve(unsigned n, unsigned m, const point_t& b, const point_t& d)
{
    const unsigned rd = b.first > d.first ? 2 * n - b.first - d.first : d.first - b.first;
    const unsigned cd = b.second > d.second ? 2 * m - b.second - d.second : d.second - b.second;

    answer(std::min(rd, cd));
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    point_t b, d;
    std::cin >> b >> d;

    solve(n, m, b, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
