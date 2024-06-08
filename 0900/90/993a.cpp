#include <array>
#include <iostream>

using point_t = std::pair<int, int>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<point_t, 4>& p, const std::array<point_t, 4>& q)
{
    const auto b = [](const std::array<point_t, 4>& s) {
        std::array<int, 4> v = { 100, -100, 100, -100 };
        for (size_t i = 0; i < 4; ++i) {
            v[0] = std::min(v[0], s[i].first);
            v[1] = std::max(v[1], s[i].first);
            v[2] = std::min(v[2], s[i].second);
            v[3] = std::max(v[3], s[i].second);
        }
        return v;
    };

    const std::array<int, 4> pb = b(p), qb = b(q);

    const auto check = [&](int x, int y) {
        return x >= pb[0] && x <= pb[1] && y >= pb[2] && y <= pb[3];
    };

    for (int d = 0; d <= (qb[1] - qb[0]) / 2; ++d) {
        for (int x = qb[0] + d; x <= qb[1] - d; ++x) {
            if (check(x, (qb[2] + qb[3]) / 2 + d) || check(x, (qb[2] + qb[3]) / 2 - d))
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<point_t, 4> p, q;
    std::cin >> p >> q;

    solve(p, q);

    return 0;
}
