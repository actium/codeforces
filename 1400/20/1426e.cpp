#include <algorithm>
#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, std::array<unsigned, 3>& a, std::array<unsigned, 3>& b)
{
    const unsigned max_a = std::min(a[0], b[1]) + std::min(a[1], b[2]) + std::min(a[2], b[0]);
    const unsigned min_a = std::min({ b[2] - (a[0] + a[2]), b[0] - (a[1] + a[0]), b[1] - (a[2] + a[1]) });

    answer(min_a > n ? 0 : min_a, max_a);
}

int main()
{
    unsigned n;
    std::cin >> n;

    std::array<unsigned, 3> a, b;
    std::cin >> a >> b;

    solve(n, a, b);

    return 0;
}

