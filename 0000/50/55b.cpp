#include <algorithm>
#include <array>
#include <iostream>

using integer = long long;

constexpr integer oo = 1000000000000;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(const std::array<int, 4>& a, const std::array<char, 3>& p)
{
    const auto f = [&](integer x, integer y, char z) {
        return z == '+' ? x + y : x * y;
    };

    const integer v1 = f(f(a[0], a[1], p[0]), f(a[2], a[3], p[1]), p[2]);
    const integer v2 = f(f(a[0], f(a[1], a[2], p[0]), p[1]), a[3], p[2]);
    return std::min(v1, v2);
}

void solve(std::array<int, 4>& a, const std::array<char, 3>& p)
{
    std::sort(a.begin(), a.end());

    integer x = oo;
    do {
        x = std::min(x, evaluate(a, p));
    } while (std::next_permutation(a.begin(), a.end()));

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<int, 4> a;
    std::cin >> a;

    std::array<char, 3> p;
    std::cin >> p;

    solve(a, p);

    return 0;
}
