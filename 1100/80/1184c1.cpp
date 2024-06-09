#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

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

void answer(const point_t& x)
{
    std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<point_t>& p)
{
    const size_t n = p.size() / 4;

    unsigned fx[51] = {}, fy[51] = {};
    for (const point_t& q : p) {
        ++fx[q.first];
        ++fy[q.second];
    }

    unsigned lx = 50, rx = 0, by = 50, ty = 0;
    for (unsigned i = 0; i <= 50; ++i) {
        if (fx[i] >= n) {
            lx = std::min(lx, i);
            rx = std::max(rx, i);
        }
        if (fy[i] >= n) {
            by = std::min(by, i);
            ty = std::max(ty, i);
        }
    }

    const auto check = [&](const point_t& q) {
        return (q.first != lx && q.first != rx || q.second < by || q.second > ty)
            && (q.second != by && q.second != ty || q.first < lx || q.first > rx);
    };

    size_t x = 0;
    while (!check(p[x]))
        ++x;

    answer(p[x]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<point_t> p(4 * n + 1);
    std::cin >> p;

    solve(p);

    return 0;
}
