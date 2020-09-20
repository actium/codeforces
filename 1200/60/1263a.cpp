#include <algorithm>
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

void solve(std::array<integer, 3>& c)
{
    std::sort(c.begin(), c.end());

    if (c[2] >= c[0] + c[1])
        answer(c[0] + c[1]);
    else
        answer((c[0] + c[1] + c[2]) / 2);
}

void test_case()
{
    std::array<integer, 3> c;
    std::cin >> c;

    solve(c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

