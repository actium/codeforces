#include <iostream>
#include <vector>

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

void answer(unsigned x, int y, int z)
{
    std::cout << x << '\n';
    std::cout << y << ' ' << z << '\n';
}

void solve(const std::vector<std::pair<int, int>>& p, int sx, int sy)
{
    const auto d = [](int x, int y, const std::pair<int, int>& t) {
        return abs(x - t.first) + abs(y - t.second);
    };

    const std::pair<int, int> c[4] = { {sx, sy-1}, {sx+1, sy}, {sx, sy+1}, {sx-1, sy} };

    unsigned k[4] = {}, b = 0;
    for (size_t i = 0; i < 4; ++i) {
        for (const auto& t : p)
            k[i] += (1 + d(c[i].first, c[i].second, t) == d(sx, sy, t));

        if (k[i] > k[b])
            b = i;
    }

    answer(k[b], c[b].first, c[b].second);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned sx, sy;
    std::cin >> sx >> sy;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    solve(p, sx, sy);

    return 0;
}

