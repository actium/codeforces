#include <array>
#include <iostream>
#include <set>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using point_t = std::pair<int, int>;

void answer(std::set<point_t>& v)
{
    std::cout << v.size() << '\n';

    for (const point_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::array<point_t, 3>& p)
{
    std::set<point_t> s;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (j == i)
                continue;

            const int dx = p[j].first - p[i].first;
            const int dy = p[j].second - p[i].second;

            const size_t k = 3 - (i + j);
            s.emplace(p[k].first + dx, p[k].second + dy);
            s.emplace(p[k].first - dx, p[k].second - dy);
        }
    }

    answer(s);
}

int main()
{
    std::array<point_t, 3> p;
    std::cin >> p;

    solve(p);

    return 0;
}

