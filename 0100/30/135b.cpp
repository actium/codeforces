#include <algorithm>
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

void answer(const std::array<size_t, 8>& v)
{
    std::cout << "YES" << '\n';

    for (size_t i = 0; i < 8; ++i)
        std::cout << 1 + v[i] << "   \n"[i&3];
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::array<point_t, 8>& p)
{
    const auto check = [&](const std::array<size_t, 8>& q) {
        for (size_t i = 0; i < 8; i += 4) {
            const int dx1 = p[q[i+1]].first - p[q[i+0]].first, dy1 = p[q[i+1]].second - p[q[i+0]].second;
            const int dx2 = p[q[i+2]].first - p[q[i+3]].first, dy2 = p[q[i+2]].second - p[q[i+3]].second;
            if (dx1 != dx2 || dy1 != dy2)
                return false;

            const int dx3 = p[q[i+3]].first - p[q[i+0]].first, dy3 = p[q[i+3]].second - p[q[i+0]].second;
            const int dx4 = p[q[i+2]].first - p[q[i+1]].first, dy4 = p[q[i+2]].second - p[q[i+1]].second;
            if (dx3 != dx4 || dy3 != dy4)
                return false;

            if (i == 0 && dx3 * dx3 + dy3 * dy3 != dx2 * dx2 + dy2 * dy2)
                return false;

            const int dx5 = p[q[i+2]].first - p[q[i+0]].first, dy5 = p[q[i+2]].second - p[q[i+0]].second;
            const int dx6 = p[q[i+3]].first - p[q[i+1]].first, dy6 = p[q[i+3]].second - p[q[i+1]].second;
            if (dx5 * dx5 + dy5 * dy5 != dx6 * dx6 + dy6 * dy6)
                return false;
        }
        return true;
    };

    std::array<size_t, 8> q = { 0, 1, 2, 3, 4, 5, 6, 7 };
    do {
        if (check(q))
            return answer(q);
    } while (std::next_permutation(q.begin(), q.end()));

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<point_t, 8> p;
    std::cin >> p;

    solve(p);

    return 0;
}
