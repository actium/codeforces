#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

bool triangle(unsigned a, unsigned b, unsigned c)
{
    return a + b > c && a + c > b && b + c > a;
}

bool segment(unsigned a, unsigned b, unsigned c)
{
    return a + b == c || a + c == b || b + c == a;
}

void answer(size_t v)
{
    constexpr const char* s[3] = { "IMPOSSIBLE", "SEGMENT", "TRIANGLE" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<unsigned, 4>& a)
{
    if (triangle(a[0], a[1], a[2]) || triangle(a[0], a[1], a[3]) || triangle(a[0], a[2], a[3]) || triangle(a[1], a[2], a[3]))
        return answer(2);

    if (segment(a[0], a[1], a[2]) || segment(a[0], a[1], a[3]) || segment(a[0], a[2], a[3]) || segment(a[1], a[2], a[3]))
        return answer(1);

    answer(0);
}

int main()
{
    std::array<unsigned, 4> a;
    std::cin >> a;

    solve(a);

    return 0;
}

