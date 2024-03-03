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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned> x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned n, unsigned m, unsigned x, unsigned y, unsigned z, std::vector<std::pair<unsigned, unsigned>>& s)
{
    for (unsigned i = 0; i < x % 4; ++i) {
        std::swap(n, m);

        for (std::pair<unsigned, unsigned>& p : s)
            p = std::make_pair(p.second, m - p.first + 1);
    }

    if (y % 2 == 1) {
        for (std::pair<unsigned, unsigned>& p : s)
            p = std::make_pair(p.first, m - p.second + 1);
    }

    for (unsigned i = 0; i < z % 4; ++i) {
        std::swap(n, m);

        for (std::pair<unsigned, unsigned>& p : s)
            p = std::make_pair(n - p.second + 1, p.first);
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, x, y, z;
    std::cin >> n >> m >> x >> y >> z;

    size_t p;
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> s(p);
    std::cin >> s;

    solve(n, m, x, y, z, s);

    return 0;
}
