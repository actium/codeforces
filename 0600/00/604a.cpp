#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::array<unsigned, 5>& m, const std::array<unsigned, 5>& w, unsigned hs, unsigned hu)
{
    constexpr unsigned c[5] = { 500, 1000, 1500, 2000, 2500 };

    unsigned s = 100 * hs;
    for (size_t i = 0; i < 5; ++i) {
        const unsigned u = c[i] - c[i] * m[i] / 250;
        const unsigned v = 50 * w[i];

        s += std::max(c[i] * 3 / 10, v > u ? 0 : u - v);
    }

    const unsigned d = 50 * hu;
    answer(s > d ? s - d : 0);
}

int main()
{
    std::array<unsigned, 5> m;
    std::cin >> m;

    std::array<unsigned, 5> w;
    std::cin >> w;

    unsigned hs, hu;
    std::cin >> hs >> hu;

    solve(m, w, hs, hu);

    return 0;
}

