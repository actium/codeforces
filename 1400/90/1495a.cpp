#include <algorithm>
#include <iostream>
#include <vector>

#include <cmath>

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

void answer(double x)
{
    std::cout.precision(10);

    std::cout << x << '\n';
}

void solve(std::vector<point_t>& p)
{
    const size_t n = p.size() / 2;

    for (point_t& q : p) {
        q.first = abs(q.first);
        q.second = abs(q.second);
    }

    std::sort(p.begin(), p.end());

    double e = 0;
    for (size_t i = 0; i < n; ++i)
        e += std::hypot(p[i].second, p[i+n].first);

    answer(e);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(2 * n);
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
