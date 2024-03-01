#include <array>
#include <iostream>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x, unsigned y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::array<std::string, 2>& a)
{
    const size_t n = a[0].length();

    size_t x = 1;
    while (x < n && a[0][x] <= a[1][x-1])
        ++x;

    const std::string t = a[0].substr(0, x) + a[1].substr(x - 1);

    unsigned k = 1;
    while (--x > 0 && a[0][x] == a[1][x-1])
        ++k;

    answer(t, k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::array<std::string, 2> a;
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
