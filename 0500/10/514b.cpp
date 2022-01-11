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

void solve(const point_t& s, std::vector<point_t>& t)
{
    const size_t n = t.size();

    const auto check = [&](size_t q) {
        const int dx1 = t[q].first - s.first, dy1 = t[q].second - s.second;

        for (size_t i = 0; i < q; ++i) {
            const int dx2 = t[i].first - s.first, dy2 = t[i].second - s.second;
            if (dy2 * dx1 == dy1 * dx2)
                return 0;
        }
        return 1;
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += check(i);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    point_t s;
    std::cin >> s;

    std::vector<point_t> t(n);
    std::cin >> t;

    solve(s, t);

    return 0;
}

