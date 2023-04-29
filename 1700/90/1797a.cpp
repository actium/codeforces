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

void solve(unsigned n, unsigned m, const point_t& p1, const point_t& p2)
{
    const auto count = [=](const point_t& p) {
        unsigned k = 4;
        k -= (p.first == 1 || p.first == n);
        k -= (p.second == 1 || p.second == m);
        return k;
    };

    const unsigned k1 = count(p1), k2 = count(p2);
    answer(std::min(k1, k2));
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    point_t p1, p2;
    std::cin >> p1 >> p2;

    solve(n, m, p1, p2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
