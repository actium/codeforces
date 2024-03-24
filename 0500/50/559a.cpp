#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<unsigned, 6>& a)
{
    const unsigned b = a[0] + a[1] + a[2];

    answer(b * b - a[0] * a[0] - a[2] * a[2] - a[4] * a[4]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<unsigned, 6> a;
    std::cin >> a;

    solve(a);

    return 0;
}
