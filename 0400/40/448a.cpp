#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, const std::array<unsigned, 3>& a, const std::array<unsigned, 3>& b)
{
    const unsigned x = a[0] + a[1] + a[2];
    const unsigned y = b[0] + b[1] + b[2];

    answer(n >= (x + 4) / 5 + (y + 9) / 10);
}

int main()
{
    std::array<unsigned, 3> a;
    std::cin >> a;

    std::array<unsigned, 3> b;
    std::cin >> b;

    size_t n;
    std::cin >> n;

    solve(n, a, b);

    return 0;
}

