#include <algorithm>
#include <iostream>
#include <vector>

using spot_t = std::pair<unsigned, unsigned>;

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

void answer(const std::vector<spot_t>& v)
{
    std::cout << v.size() << '\n';

    for (const spot_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const spot_t& a, const spot_t& b, const spot_t& c)
{
    unsigned x[3] = { a.first, b.first, c.first }, y[3] = {a.second, b.second, c.second };

    std::sort(std::begin(x), std::end(x));
    std::sort(std::begin(y), std::end(y));

    std::vector<spot_t> s;

    const auto fill = [&](unsigned lx, unsigned ux, unsigned ly, unsigned uy) {
        for (unsigned i = lx; i != ux; i < ux ? ++i : --i)
            s.emplace_back(i, ly);

        for (unsigned i = ly; i != uy; i < uy ? ++i : --i)
            s.emplace_back(lx, i);
    };

    if (x[2] - x[0] > y[2] - y[0]) {
        fill(x[0], x[2] + 1, y[1], y[1]);

        fill(a.first, a.first, a.second, y[1]);
        fill(b.first, b.first, b.second, y[1]);
        fill(c.first, c.first, c.second, y[1]);
    } else {
        fill(x[1], x[1], y[0], y[2] + 1);

        fill(a.first, x[1], a.second, a.second);
        fill(b.first, x[1], b.second, b.second);
        fill(c.first, x[1], c.second, c.second);
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    spot_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
