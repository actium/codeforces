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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    constexpr unsigned oo = ~0u;

    const size_t m = p.size();

    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(n));
    for (size_t i = 0; i < m; ++i)
        t[p[i].first-1][p[i].second-1] = i + 1;

    const auto check = [&](size_t r, size_t c) {
        unsigned x = 0;
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                if (t[r-i][c-j] == 0)
                    return oo;

                x = std::max(x, t[r-i][c-j]);
            }
        }
        return x;
    };

    unsigned z = oo;
    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 2; j < n; ++j)
            z = std::min(z, check(i, j));
    }

    answer(z);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> p(m);
    std::cin >> p;

    solve(n, p);

    return 0;
}

