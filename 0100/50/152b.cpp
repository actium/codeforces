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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m, unsigned r, unsigned c, const std::vector<std::pair<int, int>>& d)
{
    unsigned long long k = 0;
    for (const auto [dr, dc] : d) {
        unsigned dk = ~0u;
        if (dr > 0)
            dk = std::min(dk, (n - r) / dr);
        if (dr < 0)
            dk = std::min(dk, (r - 1) / -dr);
        if (dc > 0)
            dk = std::min(dk, (m - c) / dc);
        if (dc < 0)
            dk = std::min(dk, (c - 1) / -dc);

        r += dk * dr;
        c += dk * dc;
        k += dk;
    }

    answer(k);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    unsigned r, c;
    std::cin >> r >> c;

    size_t k;
    std::cin >> k;

    std::vector<std::pair<int, int>> d(k);
    std::cin >> d;

    solve(n, m, r, c, d);

    return 0;
}

