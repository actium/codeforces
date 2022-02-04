#include <algorithm>
#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;
using segment_t = std::pair<size_t, unsigned>;

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

void answer(unsigned v)
{
    constexpr const char* s[4] = { "Waste", "Carrots", "Kiwis", "Grapes" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t m, std::vector<point_t>& p, const std::vector<point_t>& q)
{
    std::sort(p.begin(), p.end());

    std::vector<segment_t> f;
    f.emplace_back(0, 1);
    for (const point_t& c : p) {
        const size_t x = (c.first - 1) * m + (c.second - 1);

        segment_t& z = f.back();
        if (x == z.first) {
            const unsigned t = z.second;
            z.second = 0;
            f.emplace_back(x + 1, t);
        } else {
            const unsigned t = (z.second + x - z.first - 1) % 3 + 1;
            f.emplace_back(x, 0);
            f.emplace_back(x + 1, t);
        }
    }

    for (const point_t& c : q) {
        const size_t x = (c.first - 1) * m + (c.second - 1);

        const auto it = std::upper_bound(f.cbegin(), f.cend(), segment_t{ x, ~0u });
        if (std::prev(it)->second == 0) {
            answer(0);
        } else {
            answer(1 + (std::prev(it)->second + x - std::prev(it)->first - 1) % 3);
        }
    }
}

int main()
{
    size_t n, m, k, t;
    std::cin >> n >> m >> k >> t;

    std::vector<point_t> p(k), q(t);
    std::cin >> p >> q;

    solve(n, m, p, q);

    return 0;
}
