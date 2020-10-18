#include <array>
#include <iostream>

using integer = unsigned long long;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(int x, int y, const std::array<unsigned, 6>& c)
{
    integer p = 1ull * abs(y) * c[y < 0 ? 4 : 1] + 1ull * abs(x) * c[x < 0 ? 2 : 5];

    const int d1 = y - x;
    p = std::min(p, 1ull * abs(d1) * c[d1 < 0 ? 4 : 1] + 1ull * abs(x) * c[x < 0 ? 3 : 0]);

    const int d2 = x - y;
    p = std::min(p, 1ull * abs(d2) * c[d2 < 0 ? 2 : 5] + 1ull * abs(y) * c[y < 0 ? 3 : 0]);

    answer(p);
}

void test_case()
{
    int x, y;
    std::cin >> x >> y;

    std::array<unsigned, 6> c;
    std::cin >> c;

    solve(x, y, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

