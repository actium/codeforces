#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::array<std::array<unsigned, 3>, 3>& v)
{
    for (const auto& x : v)
        std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
}

void solve(std::array<std::array<unsigned, 3>, 3>& a)
{
    const unsigned s = (3 * (a[1][0] + a[1][2]) + 2 * (a[0][2] + a[2][0]) + a[0][1] + a[2][1]) / 4;

    a[0][0] = s - a[0][1] - a[0][2];
    a[1][1] = s - a[1][0] - a[1][2];
    a[2][2] = s - a[2][0] - a[2][1];

    answer(a);
}

int main()
{
    std::array<std::array<unsigned, 3>, 3> a;
    std::cin >> a;

    solve(a);

    return 0;
}

