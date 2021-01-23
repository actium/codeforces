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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(point_t& a, point_t& b, const std::vector<std::pair<point_t, unsigned>>& c)
{
    if (a.first > b.first)
        std::swap(a.first, b.first);

    if (a.second > b.second)
        std::swap(a.second, b.second);

    const auto check = [&c](int x, int y) {
        for (const auto& q : c) {
            const int dx = x - q.first.first;
            const int dy = y - q.first.second;
            if (dx * dx + dy * dy <= q.second * q.second)
                return true;
        }
        return false;
    };

    unsigned k = 0;
    for (int x = a.first; x <= b.first; ++x) {
        k += !check(x, a.second);
        k += !check(x, b.second);
    }
    for (int y = a.second + 1; y < b.second; ++y) {
        k += !check(a.first, y);
        k += !check(b.first, y);
    }

    answer(k);
}

int main()
{
    point_t a, b;
    std::cin >> a >> b;

    size_t n;
    std::cin >> n;

    std::vector<std::pair<point_t, unsigned>> c(n);
    std::cin >> c;

    solve(a, b, c);

    return 0;
}

